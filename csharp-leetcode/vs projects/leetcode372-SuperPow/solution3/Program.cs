using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode372_SuperPow
{
    public class Solution
    {
        const int Mod0 = 1337;
        public int SuperPow(int a, int[] b)
        {
            if (b.Length == 0)
                return 1;

            var res = 1;
            for (int i = b.Length - 1; i >= 0; i--)
            {
                var powModResult = powMod(a, b[i]) * res;
                res = powModResult - (powModResult / Mod0) * Mod0;
                a = powMod(a, 10);
            }

            return res;
        }

        private int powMod(int a, int m)
        {
            a = a - (a / Mod0) * Mod0;
            int result = 1;
            for (int i = 0; i < m; i++)
                result = result * a - (result * a / Mod0) * Mod0;

            return result;
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
