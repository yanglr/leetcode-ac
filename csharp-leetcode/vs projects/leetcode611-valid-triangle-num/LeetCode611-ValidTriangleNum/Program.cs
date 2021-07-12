using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCode611_ValidTriangleNum
{
    public class Solution
    {
        public int TriangleNumber(int[] nums)  
        {
            var n = nums.Length;
            if (n < 3)
                return 0;

            Array.Sort(nums);
            // Array.Sort(array, (x, y) => -x.CompareTo(y));
            var groupCount = 0;

            for (int c = n - 1; c >= 2; c--)
            {
                int b = c - 1;
                int a = 0;
                while (a != b)
                {
                    if (nums[a] + nums[b] > nums[c])
                    {
                        groupCount += b - a; // 贪心法
                        b--;
                    }
                    else
                        a++;
                }
            }

            return groupCount;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = { 2,2,3,4 };
            Solution sol = new Solution();
            sol.TriangleNumber(nums);

        }
    }
}
