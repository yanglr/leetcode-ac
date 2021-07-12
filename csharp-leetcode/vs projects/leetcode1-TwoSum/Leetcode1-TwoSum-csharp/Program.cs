using System;
using System.Collections.Generic;

namespace Leetcode1_TwoSum_csharp
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int[] res = {0, 0};
            int len = nums.Length;
            Dictionary<int, int> dict = new Dictionary<int, int>();
            for (int i = 0; i < len; i++)
            {
                int query = target - nums[i];
                if (dict.ContainsKey(query))
                {
                    int min = (i <= dict[query]) ? i : dict[query];
                    int max = (i <= dict[query]) ? dict[query] : i;
                    return new int[] { min, max };
                }
                else if (!dict.ContainsKey(nums[i]))
                {
                    dict.Add(nums[i], i);
                }
            }

            return res;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] nums = { 3, 3 ,4 };
            int target = 6;
            int[] res = {0, 0};

            res = sol.TwoSum(nums, target);

            foreach (var item in res)
            {
                Console.WriteLine(item.ToString());
            }

        }
    }
}