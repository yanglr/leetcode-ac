using System;
using System.Linq;

namespace leetcode349
{
    class Program
    {
        public int[] Intersection(int[] nums1, int[] nums2)
        {
            var res = nums1.Intersect(nums2);
            return res.ToArray();
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
