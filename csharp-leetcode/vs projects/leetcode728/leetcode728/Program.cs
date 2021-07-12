using System;
using System.Collections.Generic;

namespace leetcode728
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
                if (rem > 1 && n % rem != 0)  // 原数不是末位数字倍数的数需要排除
                    return false;
                t /= 10;
            }
            return true;
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            var res = sol.SelfDividingNumbers(5, 50);
            foreach (var item in res)
                Console.WriteLine(item);
        }
    }
}
