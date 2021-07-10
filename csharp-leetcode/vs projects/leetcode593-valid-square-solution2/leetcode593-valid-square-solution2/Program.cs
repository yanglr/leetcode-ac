using System.Collections.Generic;
using System.Linq;

namespace Leetcode593_ValidSquare
{
    public class Solution
    {
        public bool ValidSquare(int[] p1, int[] p2, int[] p3, int[] p4)
        {
            if (GetLenSquare(p1, p2) == 0 || GetLenSquare(p2, p3) == 0 || GetLenSquare(p3, p4) == 0 || GetLenSquare(p1, p4) == 0)
                return false;

            return GetLenSquare(p1, p2) == GetLenSquare(p3, p4) && GetLenSquare(p1, p3) == GetLenSquare(p2, p4) && GetLenSquare(p1, p4) == GetLenSquare(p2, p3) &&
                   (GetLenSquare(p1, p2) == GetLenSquare(p1, p3) || GetLenSquare(p1, p2) == GetLenSquare(p1, p4) || GetLenSquare(p1, p3) == GetLenSquare(p1, p4));
        }

        private int GetLenSquare(int[] point1, int[] point2) => (point2[0] - point1[0]) * (point2[0] - point1[0]) +
                                                             (point2[1] - point1[1]) * (point2[1] - point1[1]);
    }

    class Program
    {
        static void Main(string[] args)
        {
            // 以下为test
            Solution sol = new Solution();
            //int[] p1 = { 0, 0 };
            //int[] p2 = { 0, 0 };
            //int[] p3 = { 0, 0 };
            //int[] p4 = { 0, 0 };

            //int[] p1 = { 1, 1 };
            //int[] p2 = { 0, 1 };
            //int[] p3 = { 1, 2 };
            //int[] p4 = { 0, 0 };
            int[] p1 = { 0, 0 };
            int[] p2 = { 1, 1 };
            int[] p3 = { 1, 0 };
            int[] p4 = { 0, 1 };
            bool result = sol.ValidSquare(p1, p2, p3, p4);
        }
    }
}
