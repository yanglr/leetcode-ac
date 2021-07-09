using System;
using System.Text;

namespace leetcode38
{
    public class Solution
    {
        public string CountAndSay(int n)
        {
            if (n == 1)
                return "1";

            string res = "1";            
            for (int i = 0; i < n - 1; i++)
            {
                StringBuilder buffer = new StringBuilder();
                char currentChar = default(char);
                int currentCharCount = 0;
                
                currentChar = res[0];

                foreach (var ch in res)
                {
                    if (ch == currentChar)
                        currentCharCount++;
                    else
                    {
                        buffer.Append(currentCharCount.ToString()).Append(currentChar);
                        currentChar = ch;
                        currentCharCount = 1;
                    }
                }

                buffer.Append(currentCharCount.ToString()).Append(currentChar);
                res = buffer.ToString();
            }

            return res;
        }

        public static void Main()
        {
            var sol = new Solution();
            Console.WriteLine(sol.CountAndSay(8));
        }
    }
}
