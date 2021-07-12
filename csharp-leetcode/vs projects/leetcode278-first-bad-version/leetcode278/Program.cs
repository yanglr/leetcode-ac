using System;

namespace leetcode278
{
    public class Solution
    {
        /* The isBadVersion API is defined in the parent class VersionControl.
      bool IsBadVersion(int version); */

        public class Solution : VersionControl
        {
            public int FirstBadVersion(int n)
            {
                int left = 0;
                int right = n;
                while (left < right)
                {
                    int mid = left + (right - left) / 2;
                    if (isBadVersion(mid))
                    {
                        right = mid;
                    }
                    else
                        left = mid + 1;
                }

                return left;
            }
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
