using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode306_AdditiveNum
{
    public class Solution
    {
        public bool IsAdditiveNumber(string num)
        {
            if (String.IsNullOrEmpty(num))
                return false;

            int len = num.Length;
            for (int i = 1; i < len; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    string s1 = num.Substring(0, i);  // Substring(startIndex, length)
                    string s2 = num.Substring(i, j - i);
                    var d1 = long.Parse(s1);
                    var d2 = long.Parse(s2);
                    var next = d1 + d2;

                    if ((s1.Length > 1 && s1[0] == '0') || (s2.Length > 1 && s2[0] == '0'))
                        continue;
                    
                    var now = s1 + s2 + next.ToString();
                    //if (num.IndexOf(now) >= 0)
                    //{
                    while (now.Length < num.Length)      // Move forward
                    {
                        d1 = d2;
                        d2 = next;
                        next = d1 + d2;
                        now += next.ToString();
                    }
                    //}
                    if (now == num)
                        return true;
                }
            }
            return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var sol = new Solution();
            var res = sol.IsAdditiveNumber("199100199");
        }
    }
}
