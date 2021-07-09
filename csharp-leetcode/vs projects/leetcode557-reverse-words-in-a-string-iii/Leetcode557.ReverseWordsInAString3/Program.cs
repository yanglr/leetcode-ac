using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode557.ReverseWordsInAString3
{
    public class Solution
    {
        public string ReverseWords(string s)
        {
            StringBuilder sb = new StringBuilder();
            s = s.Trim();
            var words = s.Split(' ');

            foreach (var word in words)
            {
                for (int i = word.Length - 1; i >= 0; i--)
                {
                    sb.Append(word[i]);
                }
                sb.Append(" ");
            }
            return sb.ToString().Trim();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
