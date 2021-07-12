using System;
using System.Collections.Generic;

namespace Leetcode633_sum_of_square_numbers
{
    public class Solution
    {
        public bool IsPerfectSquare(int num)
        {
            int i = 1;
            while (num > 0)
            {
                num -= i;
                i += 2;
            }

            if (num == 0)
                return true;
            return false;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string str;
            while ((str = Console.ReadLine()) != null)
            {
                int n = int.Parse(str);
                Solution sol = new Solution();
                bool result = sol.IsPerfectSquare(n);
                Console.WriteLine(result);
            }
        }
    }
}
