using System;
using System.Collections.Generic;

namespace leetcode78
{
    //public class Solution
    //{
    //    static void Main(string[] args)
    //    {
    //        var sol = new Solution();
    //        var res = sol.Subsets(new int[] { 1, 2, 3 });
    //    }

    //    public IList<IList<int>> Subsets(int[] nums)
    //    {
    //        double count = Math.Pow(2, nums.Length);

    //        IList<IList<int>> res = new List<IList<int>>();
    //        res.Add(new List<int>());
    //        for (int i = 1; i <= count - 1; i++)
    //        {
    //            var lst = new List<int>();
    //            string str = Convert.ToString(i, 2).PadLeft(nums.Length, '0');
    //            for (int j = 0; j < str.Length; j++)
    //            {
    //                if (str[j] == '1')
    //                {
    //                    lst.Add(nums[j]);
    //                }
    //            }
    //            res.Add(lst);
    //        }

    //        return res;
    //    }
    //}

    public class Solution
    {
        public bool JudgeSquareSum(int c)
        {
            var r = (int)Math.Sqrt(c);
            var l = 0;
            while (l <= r)
            {
                var sum = l * l + r * r;
                if (sum == c)
                    return true;

                if (sum < c)
                    l++;
                else
                    r--;
            }

            return false;
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            var res = sol.JudgeSquareSum(25);
            Console.WriteLine(res);
        }
    }
}
