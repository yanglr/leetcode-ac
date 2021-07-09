using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode413_The3rdMax
{
    public class Solution
    {
        public int ThirdMax(int[] nums)
        {
            int res = 0;
            Dictionary<int, int> dict = new Dictionary<int, int>();
            foreach (var num in nums)
            {
                if (!dict.ContainsKey(num))
                    dict.Add(num, 1);
                else dict[num]++;
            }
            var list = dict.ToList();
            list.Sort((x, y) => -x.Key.CompareTo(y.Key));
            dict.OrderByDescending(kv => kv.Key);

            if (list.Count > 2)
                res = list.ElementAtOrDefault(2).Key;
            else
            {
                res = list.First().Key;
            }

            return res;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int res = sol.ThirdMax(new int[] { 1,2 });

        }
    }
}
