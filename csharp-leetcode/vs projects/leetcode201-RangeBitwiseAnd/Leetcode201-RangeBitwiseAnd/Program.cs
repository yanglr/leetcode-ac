using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode201_RangeBitwiseAnd
{
    class Program
    {
        public class Solution
        {
            public int RangeBitwiseAnd(int m, int n)
            {
                // 题中规定数据范围: m,n中较大值<=31s
                int shiftCount = 0;
                int common = 0;
                GetCommonDigits(m, n, ref common, ref shiftCount);
                var res = common << shiftCount;  // 末位补0

                return res;
            }
        
            public void GetCommonDigits(int a, int b, ref int common, ref int shiftCount)
            {
                shiftCount = 0;
                while (a != b)
                {
                    a = a >> 1;
                    b = b >> 1;
                    shiftCount++;
                }
                common = a;
            }
        }
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.RangeBitwiseAnd(20, 23);

        }
    }
}
