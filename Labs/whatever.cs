using System;
using System.Collections.Generic;
using System.Text;

namespace OOPWeek5May26
{
    internal class Chair
    {
        // Fields
        private string material;
        private string color;
        private int numberOfLegs;

        private Position position;



        // Constructor
        public Chair(string material, string color, int numberOfLegs)
        {
            this.material = material;
            this.color = color;
            this.numberOfLegs = numberOfLegs;
        }
        // Method to display chair information
        public void DisplayInfo()
        {
            Console.WriteLine($"Chair Material: {material}");
            Console.WriteLine($"Chair Color: {color}");
            Console.WriteLine($"Number of Legs: {numberOfLegs}");
        }


        public void MoveToPosition(Position newPosition)
        {
            position = newPosition;
            Console.WriteLine($"Chair moved to new position: ({position.x}, {position.y})");
        }

        public void SetPosition(Position newPosition) { position = newPosition; }

        public Position GetPosition() { return position; }

        public void MoveLeft()
        {

        }

        public static void CenterAll()
        {
            position_x = 0;
            position_y = 0;
        }



    }

    class program {
        
        Chair.CenterAll()

    }

        
}