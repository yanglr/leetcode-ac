using System;

namespace Leetcode_single_number2
{
    public class Solution
    {
        public int SingleNumber(int[] nums)
        {
            int a = 0, b = 0;
            for(int i = 0;i < nums.Length;i++)
            {
                b = (b ^ nums[i]) & ~a;
                a = (a ^ nums[i]) & ~b;
            }
            return b;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] nums = { 1, 2, 2, 2, 1, 1, 80 };
            Console.WriteLine(sol.SingleNumber(nums));
        }
    }
}
