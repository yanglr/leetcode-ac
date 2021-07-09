using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode633
{
    public class Optimization1
    {
        public bool JudgeSquareSum(int c)
        {
            for (int i = 0; c - 2 * i * i >= 0; i++)
            {
                int diff = c - i * i;
                if (IsPerfectSquare(diff))
                    return true;
            }

            return false;
        }
        private bool IsPerfectSquare(int num)
        {
            double sq1 = Math.Sqrt(num);
            int sq2 = (int)Math.Sqrt(num);
            if (Math.Abs(sq1 - (double)sq2) < 10e-10)
                return true;
            return false;
        }

        //public static void Main(string[] args)
        //{
        //    Solution sol = new Solution();
        //    Console.WriteLine(sol.JudgeSquareSum(25));
        //}
    }
}
