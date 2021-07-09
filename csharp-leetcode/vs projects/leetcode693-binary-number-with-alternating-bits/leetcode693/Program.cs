using System;

namespace leetcode693
{
    public class Solution
    {

        public bool HasAlternatingBits(int n)
        {
            string str = Convert.ToString(n, 2);
            if (str.IndexOf("00", StringComparison.Ordinal) != -1 || str.IndexOf("11", StringComparison.Ordinal) != -1)
                return false;

            return true;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
