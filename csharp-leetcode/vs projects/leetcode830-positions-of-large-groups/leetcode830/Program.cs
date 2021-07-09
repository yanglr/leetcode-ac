using System;
using System.Collections.Generic;

namespace leetcode830
{
    public class Solution
    {
        public IList<IList<int>> LargeGroupPositions(string S)
        {
            // Setup initial state
            List<IList<int>> group = new List<IList<int>>();
            // Loop thru all the groups
            for (int i = 0; i < S.Length;)  // i as slow point, fast( >= i) as fast point
            {
                // Reset inner loop state
                int fast = i, maxCount = 0;
                // Calculate group size
                while (fast < S.Length && S[i] == S[fast])
                {
                    maxCount++;
                    fast++;
                }
                // Estimate group size and count in if needed
                if (maxCount >= 3)
                    group.Add(new[] { i, fast - 1 });
                // Move start head to the beginning of the next group
                i += maxCount;
            }
            // Here is the list of large groups
            return group;
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            Console.WriteLine(sol.LargeGroupPositions("abcdddeeeeaabbbcd"));
        }
    }
}
