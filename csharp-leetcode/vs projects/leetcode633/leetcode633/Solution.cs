using System;

namespace leetcode633
{
    public class Solution
    {
        public bool JudgeSquareSum(int c)
        {
            for (int i = 0; c - 2 * i * i >= 0; i++)
            {
                double diff = c - i * i;
                // 若向上取整=向下取整，则该数开方后是整数
                if ((int)(Math.Ceiling(Math.Sqrt(diff))) == (int)(Math.Floor(Math.Sqrt(diff))))
                    return true;
            }

            return false;
        }

        public static void Main(string[] args)
        {
            Solution sol = new Solution();
            Console.WriteLine(sol.JudgeSquareSum(25));
        }
    }
}
