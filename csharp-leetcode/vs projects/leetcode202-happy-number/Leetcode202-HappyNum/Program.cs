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
            bool isHappy = default(bool);
            List<int> list = new List<int>();

            if (n == 4)
                return false;


            while (list.LastOrDefault() != 4)
            {
                var s = getSquareSum(n);
                list.Add(s);
                if (list.FirstOrDefault(x => x == 4) != null)
                    break;
            }

            if (n == 1)
                isHappy = true;
            return isHappy;
        }

        private int getSquareSum(int n)
        {
            if (n < 10)
                return n * n;

            int sum = 0;
            while (n % 10 != 0)
            {
                var r = n / 10;
                sum += r*r;
                n = n / 10;
            }

            return sum;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.IsHappy(19);
            Console.WriteLine(res);
        }
    }
}
