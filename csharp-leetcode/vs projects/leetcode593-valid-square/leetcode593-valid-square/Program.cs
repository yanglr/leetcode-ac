using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode593-valid-square
{
    public class Solution
    {
        public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            HashSet<int> set = new HashSet<int>
            {
                GetLenSquare(p1, p2),
                GetLenSquare(p1, p3),
                GetLenSquare(p1, p4),
                GetLenSquare(p2, p3),
                GetLenSquare(p2, p4),
                GetLenSquare(p3, p4)
            };

            if (!set.Any(x => x == 0) && set.Count == 2)
            {
                return true;
            }

            return false;
        }

        private int GetLenSquare(int[] point1, int[] point2) => (point2[0] - point1[0]) * (point2[0] - point1[0]) +
                                                                (point2[1] - point1[1]) * (point2[1] - point1[1]);

        public static void Main(string[] args)
        {
            var sol = new Solution();
            var p1 = new []{0, 0};
            var p2 = new []{1, 1};
            var p3 = new []{1, 0};
            var p4 = new []{0, 1};
            Console.WriteLine(sol.ValidSquare(p1, p2, p3, p4));
        }
    }
}
