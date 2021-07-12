using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode191_NumberOf1
{
    public class Solution
    {
        public int HammingWeight(uint n)
        {
            int count = 0;
            while (n > 0)
            {
                n = n & (n - 1);
                count++;
            }                

            return count;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
