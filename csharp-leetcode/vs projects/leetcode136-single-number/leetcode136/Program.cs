using System.Collections.Generic;
using System.Linq;

namespace leetcoce136a
{
    public class Solution
    {
        public int SingleNumber(int[] nums)
        {
            int res = 0;
            Dictionary<int, int> dict = new Dictionary<int, int>();
            foreach (var num in nums)
            {
                if (!dict.ContainsKey(num))
                {
                    dict.Add(num, 1);
                }
                else
                    dict[num]++;
            }

            res = dict.FirstOrDefault(kv => kv.Value == 1).Key;

            return res;
        }

        public static void Main()
        {
            var sol = new Solution();
            int[] input = { 4, 1, 2, 1, 2 };

            System.Console.WriteLine(sol.SingleNumber(input));
        }
    }
}