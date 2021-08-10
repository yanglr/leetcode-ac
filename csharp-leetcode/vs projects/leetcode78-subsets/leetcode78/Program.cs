using System;
using System.Linq;
using System.Collections.Generic;

namespace leetcode78 {
    public class Solution {
        public IList<IList<int>> Subsets(int[] nums) {
            double count = Math.Pow(2, nums.Length);    /* 大的思路: 转为二进制(长度与原数组中数字个数相等)的字符串, 然后枚举. 由于各个元素中不存在相等的数，于是每个二进制数位都有出现/不出现(0, 1)两种状态, 共有2^n组  */
            IList<IList<int>> res = new List<IList<int>>();
            res.Add(new List<int>());
            for (int i = 1; i < count; i++) {
                var curSet = new List<int> ();
                string str = Convert.ToString(i, 2).PadLeft(nums.Length, '0');  /* Convert.ToString(i, 2)表示转为二进制的字符串, PadLeft表示如果位数不够会在左侧填补上字符'0' */
                for (int j = 0; j < str.Length; j++)
                {
                    if (str[j] == '1')
                        curSet.Add(nums[j]);
                }
                res.Add(curSet);
            }

            return res;
        }

        static void Main (string[] args) {
            var sol = new Solution ();
            var res = sol.Subsets(new int[] { 1, 2, 3 });
            foreach (var theSet in res)
            {
                theSet.ToList().ForEach(x => Console.Write(x + ","));
                Console.WriteLine();
            }
        }
    }
}