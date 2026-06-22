/******************************************************************************
Homework 5

Student Name: Momen Elhag
Student ID  : 25014926

Note:
The read(fname) function assumes the file is a pristine CSV formatted 
exactly as [time, value]. If the file contains headers, letters, or ancient 
hieroglyphs, the program will panic and crash. Please be gentle.

*******************************************************************************/

using System;
using System.IO;
using System.Collections.Generic;

public class SensorReading
{
    public float val { get; set; }
    public int time { get; set; }
    
    public SensorReading(float val, int time)
    {
        this.val = val;
        this.time = time;
    }
    
    public void Display()
    {
        Console.WriteLine($"Time: {time}ms, Value: {val}F");
    }
    
    public void Standardize()
    {
        val = (val - 32f) * (5f / 9f);
    }
}

public class SensorData
{
    private SensorReading[] temperature;

    public SensorData()
    {
        temperature = new SensorReading[0]; 
    }
    
    public float calcAverage()
    {
        if(temperature.Length == 0)
        {
            return 0f;
        }
        
        float sum = 0;
        foreach(SensorReading shinanigan in temperature)
        {
            sum += shinanigan.val;
        }
        
        return sum/temperature.Length;
    }
    
    public float[] getHigherTemperature(float thres)
    {
        List<float> furnace = new List<float>();

        foreach(SensorReading shinanigan in temperature)
        {
            if(shinanigan.val > thres)
            {
                furnace.Add(shinanigan.val);
            }
        }

        return furnace.ToArray();
    }

    public void read()
    {
        List<SensorReading> plasticBag = new List<SensorReading>();
        Console.WriteLine("Enter time and temperature separated by a comma (type 'done' to finish):");

        while(true)
        {
            string input = Console.ReadLine();

            if(input == "done")
            {
                break;
            }

            string[] parts = input.Split(',');

            int parsedTime = int.Parse(parts[0]);
            float parsedVal = float.Parse(parts[1]);

            SensorReading newReading = new SensorReading(parsedVal, parsedTime);
            plasticBag.Add(newReading);
        }

        temperature = plasticBag.ToArray();
    }

    public void read(string fname)
    {
        List<SensorReading> rustyBucket = new List<SensorReading>();

        string filePath = fname;

        if (File.Exists(filePath))
        {
            string[] lines = File.ReadAllLines(filePath);
    
            foreach (string line in lines)
            {
                string[] parts = line.Split(',');  

                int parsedTime = int.Parse(parts[0]);
                float parsedVal = float.Parse(parts[1]);

                SensorReading newReading = new SensorReading(parsedVal, parsedTime);
                rustyBucket.Add(newReading);
            }

            temperature = rustyBucket.ToArray();
        }    
    }
}

public class Program
{
    static void Main(string[] args)
    {
    
    //Note: the following tests are AI generated so take them with a grain of salt. Matter of fact take them with the whole salter.

    // 1. Create a brand new SensorData object
    SensorData myData = new SensorData();

    // 2. Test the keyboard reader
    Console.WriteLine("--- TESTING KEYBOARD INPUT ---");
    myData.read(); 

    // 3. Test the math
    Console.WriteLine("\n--- TESTING MATH ---");
    float average = myData.calcAverage();
    Console.WriteLine($"The average temperature is: {average}F");

    // 4. Test the Furnace (Threshold filter)
    Console.WriteLine("\n--- TESTING THE FURNACE (Temperatures over 80F) ---");
    float[] hotTemps = myData.getHigherTemperature(80f);
    
    if (hotTemps.Length == 0)
    {
        Console.WriteLine("No temperatures were higher than the threshold.");
    }
    else
    {
        foreach (float hotVal in hotTemps)
        {
            Console.WriteLine($"Found a hot one: {hotVal}F");
        }
    }
    
    Console.WriteLine("\nTesting complete. Press any key to exit.");
    Console.ReadKey();

    }
}