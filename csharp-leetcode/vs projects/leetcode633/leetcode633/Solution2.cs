using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode633
{
    public class Solution2
    {
        public class Solution
        {
            public bool JudgeSquareSum(int c)
            {
                for (int i = 0; c - 2 * i * i >= 0; i++)
                {
                    double diff = c - i * i;
                    if (Math.Abs(Math.Sqrt(diff) % 1) < 0.000001)
                        return true;
                }

                return false;
            }
        }

        //public static void Main(string[] args)
        //{
        //    Solution sol = new Solution();
        //    Console.WriteLine(sol.JudgeSquareSum(25));
        //}
    }
}
