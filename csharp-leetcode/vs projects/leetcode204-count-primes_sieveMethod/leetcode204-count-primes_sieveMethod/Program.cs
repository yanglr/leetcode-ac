using System;

namespace Leetcode204_GetPrime_SieveMethod
{
    public class Solution
    {
        public int CountPrimes(int n)
        {
            if (n < 2) return 0;
            bool[] isDelete = new bool[n];
            int max = (int) Math.Sqrt(n);
            var count = 0;
            for (int i = 2; i < n; i++)
            {
                if (isDelete[i])
                    continue;
                count++;
                if (i > max)
                    continue;
                for (int j = i * i; j < n; j += i)
                    isDelete[j] = true;
            }
            return count;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var result = sol.CountPrimes(100156150);
            Console.WriteLine(sol);
        }
    }
}
