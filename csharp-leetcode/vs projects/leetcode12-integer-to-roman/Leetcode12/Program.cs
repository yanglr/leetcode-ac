using System;
using System.Collections.Generic;

namespace Leetcode12
{
    public class Solution
    {
        public string IntToRoman(int num)
        {
            string res = String.Empty;
            List<int> val = new List<int> { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
            List<string> str = new List<string> { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
            for(int i = 0;i < val.Count; ++i)
            {
                while(num >= val[i])
                {
                    num -= val[i];
                    res += str[i];
                }
            }
            return res;
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
                Console.WriteLine(sol.IntToRoman(int.Parse(str)));
            }
        }
    }
}
