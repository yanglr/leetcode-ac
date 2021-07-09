using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode89_GrayCode
{
    public class Solution
    {
        public IList<int> GrayCode(int n)
        {            
            int len = 1<<n;
            IList<int> res = new List<int>(len);
            for (int i = 0; i < len; i++)
            {
                res.Add(i ^ (i >> 1));
            }

            return res;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.GrayCode(2);

        }
    }
}
