using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode372_SuperPow
{
    public class Solution
    {
        public int SuperPow(int a, int[] b)
        {
            int res = 0;
            StringBuilder sb = new StringBuilder();
            foreach (var item in b)
                sb.Append(item);
            int.TryParse(sb.ToString(), out int p);
            var val = (int)Math.Pow(a, p);
            res = val - (val / 1337) * 1337;  // val%1337 == val - (val / 1337) * 1337

            return res;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.SuperPow(2147483647, new int[] { 2, 0, 0 });
            Console.WriteLine(res);
        }
    }
}
