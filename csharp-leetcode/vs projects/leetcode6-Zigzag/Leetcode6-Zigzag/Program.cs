using System;
using System.Text;

namespace Leetcode6_Zigzag
{
    public class Solution
    {
        public string Convert(string s, int numRows)
        {
            StringBuilder sb = new StringBuilder();
            // base case
            if (numRows == 1)
                return s;

            // handle first row
            for (int i = 0; i < s.Length; i += (numRows - 1) * 2)
                sb.Append(s[i]);

            // handle middle rows
            for (int j = 1; j < numRows - 1; j++)
            {
                bool down = true;
                for (int i = j; i < s.Length;)
                {
                    sb.Append(s[i]);
                    if (down) // going down
                        i += (numRows - 1 - j) * 2;
                    else // going up
                        i += 2*j;

                    down = !down; // switch direction
                }
            }

            // handle last row
            for (int i = numRows - 1; i < s.Length; i += (numRows - 1) * 2)
                sb.Append(s[i]);

            return sb.ToString();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
                Solution sol = new Solution();
                String str = "PAYPALISHIRING";
                int numRows = 4;

                var res = sol.Convert(str, numRows);
                Console.WriteLine(res);
        }
    }
}
