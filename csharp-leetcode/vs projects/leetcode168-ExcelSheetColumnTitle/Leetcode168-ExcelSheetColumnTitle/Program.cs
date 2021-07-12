using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode168_ExcelSheetColumnTitle
{
    public class Solution
    {
        public string ConvertToTitle(int n)
        {
            var list = new List<int>();
            StringBuilder sb = new StringBuilder();
            while (n != 0)
            {
                if (n % 26 == 0)
                {
                    sb.Append('Z');
                    n -= 26;
                }
                else
                {
                    var rem = n % 26;
                    sb.Append((char)(rem - 1 + 'A'));
                }
                n /= 26;
            }

            char[] charArr = sb.ToString().ToCharArray();
            Array.Reverse(charArr);
            return new string(charArr);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            var res = sol.ConvertToTitle(26);
            Console.WriteLine(res);
        }
    }
}
