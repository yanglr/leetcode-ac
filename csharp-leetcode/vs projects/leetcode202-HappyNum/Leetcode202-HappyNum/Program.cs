using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode202_HappyNum
{
    public class Solution
    {
        public bool IsHappy(int n)
        {
            HashSet<int> unhappy = new HashSet<int>();
            while (n != 1 && !unhappy.Contains(n))
            {
                unhappy.Add(n);
                int sum = 0;
                while (n != 0)
                {
                    var r = n - (n / 10) * 10;
                    sum += r * r;
                    n /= 10;
                }
                n = sum;
            }
            return n == 1;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            bool isHappy = sol.IsHappy(2);
            Console.WriteLine(isHappy);
        }
    }
}
