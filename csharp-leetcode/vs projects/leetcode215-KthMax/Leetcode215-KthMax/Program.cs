using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode215_KthMax
{
    public class Solution
    {
        public IList<int> TopKFrequent(int[] nums, int k)
        {
            var dict = new Dictionary<int, int>();
            IList<int> result = new List<int>();
            foreach (var num in nums)
            {
                if (!dict.ContainsKey(num))
                    dict.Add(num, 1);
                else dict[num]++;
            }
            var r = dict.OrderByDescending(f => f.Value).Take(k).ToList();

            for (int i = 0; i < k; i++)
                result.Add(r.ElementAtOrDefault(i).Key);     

            return result;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
