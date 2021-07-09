using System;
using System.Collections.Generic;
using System.Linq;

namespace leetcode771
{
    public class Solution
    {
        public int NumJewelsInStones(string J, string S)
        {
            int jCount = 0;

            S.ToCharArray().GroupBy(c => c).ToList().ForEach(s => {
                if (J.Contains(s.Key))
                    jCount += s.Count();
            });

            return jCount;
        }

        static void Main(string[] args)
        {
            var sol = new Solution();
            string J = "aA";
            string S = "azAtttta";
            Console.WriteLine(sol.NumJewelsInStones(J, S));
        }
    }
}
