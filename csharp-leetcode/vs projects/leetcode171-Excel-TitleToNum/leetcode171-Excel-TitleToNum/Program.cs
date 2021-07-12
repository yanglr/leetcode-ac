using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode171_Excel_TitleToNum
{
    class Program
    {
        public class Solution
        {
            public int TitleToNumber(string s)
            {
                int len = s.Length;
                int sum = 0;
                int weigh = 1;        // 该位的权, 26^0 ~ 26^(n-1)
                for (int i = len; i >= 1; i--)
                {
                    sum += (s[i - 1] - 'A' + 1) * weigh;  // 从低位开始累加
                    weigh *= 26;
                }
                return sum;
            }
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.TitleToNumber("AAA");
        }
    }
}
