using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode633
{
    public class Optimization3
    {
        public bool JudgeSquareSum(int c)
        {
            for (int i = 0; c - i * i >= 0; i++)
            {
                long diff = c - i * i;
                if (IsSquareFast(diff))
                    return true;
            }

            return false;
        }

        bool IsSquareFast(long n)
        {
            if ((0x2030213 & (1 << (int)(n & 31))) > 0)
            {
                long t = (long)Math.Round(Math.Sqrt((double)n));
                bool result = t * t == n;
                return result;
            }
            return false;
        }

        //public static void Main(string[] args)
        //{
        //    Solution sol = new Solution();
        //    Console.WriteLine(sol.JudgeSquareSum(25));
        //}
    }
}
