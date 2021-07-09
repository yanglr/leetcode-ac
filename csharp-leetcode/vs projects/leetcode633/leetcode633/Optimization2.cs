using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode633
{
    public class Optimization2
    {
        public bool JudgeSquareSum(int c)
        {
            for (int i = 0; i <= c && c - i * i >= 0; i++)
            {
                int diff = c - i * i;
                if (IsPerfectSquare(diff))
                    return true;
            }

            return false;
        }
        public bool IsPerfectSquare(int num)
        {
            // TRUE only if n mod 16 is 0, 1, 4, or 9
            if ((0x0213 & (1 << (num & 15))) != 0)
            {
                int t = (int)Math.Floor(Math.Sqrt((double)num) + 0.5);
                return t * t == num;
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
