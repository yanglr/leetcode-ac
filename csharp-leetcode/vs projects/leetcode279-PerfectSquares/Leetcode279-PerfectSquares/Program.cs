using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode279_PerfectSquares
{
    class Program
    {
        public class Solution
        {
            public int NumSquares(int n)  // 已知 n>0
            {
                while (n % 4 == 0)
                    n /= 4;

                if (n % 8 == 7)
                    return 4;

                for (int i = 0; i * i <= n; i++)
                {
                    int r = (int)Math.Sqrt(n - i * i);
                    if (i * i + r * r == n)
                    {
                        if (i == 0 || r == 0)
                            return 1;

                        return 2;
                    }
                }

                return 3;
            }
        }
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string str = String.Empty;
            while ((str = Console.ReadLine()) != null)
            {
                int n = int.Parse(str);
                int result = sol.NumSquares(n);
                Console.WriteLine(result);
            }
        }
    }
}
