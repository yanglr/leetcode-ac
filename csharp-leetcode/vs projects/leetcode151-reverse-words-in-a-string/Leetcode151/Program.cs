using System;
using System.Text;

namespace Leetcode151_ReverseWordsInString
{
    public class Program
    {
        public class Solution
        {
            public string ReverseWords(string s)
            {
                StringBuilder sb = new StringBuilder();
                s = s.Trim();
                s = s.Replace("  ", " ");
                var words = s.Split(' ');
                for (int i = words.Length; i > 0; i--)
                {
                    foreach (var ch in words[i-1])
                    {
                        sb.Append(ch);
                    }
                    sb.Append(" ");
                }
                return sb.ToString().Trim();
            }
        }
        public static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.ReverseWords("   a   b ");
            Console.WriteLine(res);
        }
    }
}
