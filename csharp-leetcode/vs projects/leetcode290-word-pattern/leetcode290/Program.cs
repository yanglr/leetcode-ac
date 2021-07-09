using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode290
{
    public class Solution
    {
        public bool WordPattern(string pattern, string str)
        {
            List<int> indexP = new List<int>();
            List<int> indexS = new List<int>();

            for (int i = 0; i < pattern.Length; i++)
                indexP.Add(pattern.IndexOf(pattern[i]));

            var arr = str.Split(' '); // 出现在第几个word的位置?即在split数组中的位置

            for (int i = 0; i < arr.Length; i++)
                indexS.Add(arr.ToList().FindIndex(s => s == arr[i]));

            return indexS.SequenceEqual(indexP);
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.WordPattern("abba", "dog cat cat dog"));
        }
    }
}