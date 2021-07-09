using System;

namespace LeetCode_6ZigZagConversion
{
    public class Solution
    {
        public string Convert(string s, int numRows)
        {
            char[] res = new char[s.Length];
            // string res = new string(' ', s.Length);
            if (numRows <= 1)
                return s;

            int pos = 0;
            for (int i = 0; i < numRows; i++)
            {
                int gap1 = 2 * (numRows - 1 - i);
                int gap2 = 2 * i;

                int index = i;
                while (pos < s.Length)
                {
                    if (gap1 > 0)
                    {
                        if (index >= s.Length)
                            break;
                        res[pos++] = s[index];  // Add char row by row
                        index += gap1;
                    }

                    if (gap2 > 0)
                    {
                        if (index >= s.Length)
                            break;
                        res[pos++] = s[index];
                        index += gap2;
                    }
                }
            }

            return new string(res);
        }
    }

    class Program
    {        
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string res = sol.Convert("PAYPALISHIRING", 3);
            Console.WriteLine(res);
        }
    }
}
