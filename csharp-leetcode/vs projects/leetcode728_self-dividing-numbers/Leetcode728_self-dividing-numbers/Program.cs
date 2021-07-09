using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode728_self_dividing_numbers
{
    public class Solution
    {
        public IList<int> SelfDividingNumbers(int left, int right)
        {
            List<int> list = new List<int>();
            for (int i = left; i <= right; ++i)
            {
                if (isSelfDiv(i))
                    list.Add(i);
            }
            return list;
        }

        bool isSelfDiv(int n)
        {
            if (n < 10)
                return true;
            if (n % 10 == 0)
                return false;

            int t = n;
            while (t != 0)
            {
                int rem = t % 10;
                if (rem == 0)
                    return false;
                if (rem >1 && n % rem != 0)
                    return false;
                t /= 10;
            }
            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            var sol = new Solution();
            sol.SelfDividingNumbers(2, 30);

        }
    }
}
