using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode507_PerfectNum
{
    public class Solution
    {
        public bool CheckPerfectNumber(int num)
        {
            if (num == 1)
                return false;

            int[] divisors = {};
            for (int i = 2; i*i<=num; i++)  // Store the smaller one in divisor pair, then another is num/smaller
            {
                if (num - (num/i) * i == 0)
                    divisors = divisors.Concat(new int[]
                    {
                       i
                    }).ToArray();
            }

            int sum = 1;   // 1 is divisor of any integer
            foreach (var divisor in divisors)
                sum += divisor + num/divisor;
            return num == sum;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.CheckPerfectNumber(28));
        }
    }
}
