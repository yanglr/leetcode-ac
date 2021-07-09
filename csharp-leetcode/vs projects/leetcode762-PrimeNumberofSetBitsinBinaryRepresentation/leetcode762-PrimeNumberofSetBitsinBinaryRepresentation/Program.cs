using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace leetcode762_PrimeNumberofSetBitsinBinaryRepresentation
{
    public class Solution
    {
        public int CountPrimeSetBits(int L, int R)
        {
            int count = 0;
            for (int i = L; i < R; i++)
            {
                if (IsPrime(CountOf1(i)))
                    count++;
            }

            return count;
        }

        public int CountOf1(int n)
        {
            int count = 0;
            while (n != 0)
            {
                n = n & (n - 1);
                count++;
            }
            return count;
        }

        public bool IsPrime(int m)
        {
            for (int i = 2; i*i <= m; i++)
            {
                if (m % i == 0)
                    return false;
            }
            return true;
        }
    }

    class Program
    {        
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int count = sol.CountPrimeSetBits(2, 8);

        }
    }
}
