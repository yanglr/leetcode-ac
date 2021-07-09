using System;
using System.Collections.Generic;
using System.Text;

namespace leetcode345
{
    public class Solution
    {
        public string ReverseVowels(string s)
        {
            var vowels = new List<char> { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
            int vCount = 0;

            List<char> vList = new List<char>();
            for (int i = 0; i < s.Length; i++)
            {
                var ch = s[i];
                if (vowels.Contains(ch))
                {
                    vList.Add(ch);
                    vCount++;
                }
            }

            vList.Reverse();

            StringBuilder buffer = new StringBuilder();
            int vOutCount = 0;
            for (int i = 0; i < s.Length; i++)
            {
                var ch = s[i];
                if (!vowels.Contains(ch))
                    buffer.Append(ch);
                if (vowels.Contains(ch))
                {
                    buffer.Append(vList[vOutCount]);
                    vOutCount++;
                }
            }

            return buffer.ToString();
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.ReverseVowels("aA"));
        }
    }
}
