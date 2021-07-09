using System;
using System.Collections.Generic;

namespace Leetcode49_GroupAnagrams
{
    public class Solution
    {
        public IList<IList<string>> GroupAnagrams(string[] strs)
        {
            IList<IList<string>> res = new List<IList<string>>();
            if (strs == null || strs.Length == 0)
                return res;

            Dictionary<string, int> dict = new Dictionary<string,int>();
            foreach (var str in strs)
            {
                char[] ch = str.ToCharArray();
                Array.Sort(ch);
                string s = new string(ch);
                if (dict.ContainsKey(s))
                {
                    IList<string> list = res[dict[s]];
                    list.Add(str);
                }
                else
                {
                    IList<string> list = new List<string>();
                    list.Add(str);
                    dict.Add(s, res.Count);
                    res.Add(list);
                }
            }

            return res;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };

            var result = sol.GroupAnagrams(strs);
            Console.WriteLine(result);
        }
    }
}
