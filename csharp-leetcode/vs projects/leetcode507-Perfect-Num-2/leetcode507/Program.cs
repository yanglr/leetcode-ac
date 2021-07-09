using System;

namespace leetcode507
{
    public class Solution
    {
        public bool CheckPerfectNumber(int num)
        {
            return num == 6 || num == 28 || num == 496 || num == 8128 || num == 33550336;
        }

        public static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.CheckPerfectNumber(60));
        }
    }
}
