using System;

public class Reading
{
    public float temp;
    public int time;
}

public class Sensor
{
    public string name;
    public Reading[] data = new Reading[10];

    public void ReadAll()
    {
        Console.WriteLine("\nReading data for: " + name);
        for (int i = 0; i < 10; i++)
        {
            data[i] = new Reading(); 
            
            Console.Write("Enter Temp " + i + ": ");
            data[i].temp = float.Parse(Console.ReadLine());
            
            Console.Write("Enter Time " + i + ": ");
            data[i].time = int.Parse(Console.ReadLine());
        }
    }

    public void ShowMinMax()
    {
        float min = data[0].temp;
        float max = data[0].temp;

        for (int i = 1; i < 10; i++)
        {
            if (data[i].temp < min) min = data[i].temp;
            if (data[i].temp > max) max = data[i].temp;
        }
        Console.WriteLine(name + " - Min: " + min + ", Max: " + max);
    }

    public void ShowAvg()
    {
        float sum = 0;
        for (int i = 0; i < 10; i++)
        {
            sum = sum + data[i].temp;
        }
        float avg = sum / 10;
        Console.WriteLine(name + " - Average: " + avg);
    }

    public void ShowHigher(float limit)
    {
        Console.WriteLine(name + " - Temps above " + limit + ":");
        for (int i = 0; i < 10; i++)
        {
            if (data[i].temp > limit)
            {
                Console.WriteLine("Temp: " + data[i].temp + " at Time: " + data[i].time);
            }
        }
    }
}

class Program
{
    static void Main()
    {
        Sensor loc1 = new Sensor();
        loc1.name = "Kitchen";
        loc1.ReadAll();

        Sensor loc2 = new Sensor();
        loc2.name = "Living Room";
        loc2.ReadAll();

        while (true)
        {
            Console.WriteLine("\nOptions: 1=Min/Max, 2=Avg, 3=Filter, 4=Reread, 5=Exit");
            Console.Write("Choose an option: ");
            string choice = Console.ReadLine();

            if (choice == "5") 
            {
                break; 
            }
            else if (choice == "1")
            {
                loc1.ShowMinMax();
                loc2.ShowMinMax();
            }
            else if (choice == "2")
            {
                loc1.ShowAvg();
                loc2.ShowAvg();
            }
            else if (choice == "3")
            {
                Console.Write("Enter limit: ");
                float limit = float.Parse(Console.ReadLine());
                loc1.ShowHigher(limit);
                loc2.ShowHigher(limit);
            }
            else if (choice == "4")
            {
                loc1.ReadAll();
                loc2.ReadAll();
            }
            else
            {
                Console.WriteLine("Invalid choice.");
            }
        }
    }
}