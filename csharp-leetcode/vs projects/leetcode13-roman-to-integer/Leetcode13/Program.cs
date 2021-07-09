using System;
using System.Collections.Generic;

namespace Leetcode13
{
    public class Solution
    {
        static readonly Dictionary<char, int> dict = new Dictionary<char, int>
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        public int RomanToInt(string s)
        {
            int sum = 0;
            for(int i = 0;i < s.Length;i++)
            {
                int currentValue = dict[s[i]];
                if(i == s.Length - 1 || dict[s[i + 1]] <= currentValue)
                    sum += currentValue;
                else
                    sum -= currentValue;
            }
            return sum;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string str;
            while((str = Console.ReadLine()) != null)
            {
                Solution sol = new Solution();
                Console.WriteLine(sol.RomanToInt(str));
            }
        }
    }
}
