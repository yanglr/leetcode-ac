using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode205
{
    public class Solution
    {
        public bool IsIsomorphic(string s, string t)
        {
            List<int> indexS = new List<int>();
            List<int> indexT = new List<int>();

            for (int i = 0; i < s.Length; i++)
                indexS.Add(s.IndexOf(s[i]));

            for (int j = 0; j < t.Length; j++)
                indexT.Add(t.IndexOf(t[j]));

            return indexS.SequenceEqual(indexT);
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.IsIsomorphic("paper", "title"));
        }
    }
}
