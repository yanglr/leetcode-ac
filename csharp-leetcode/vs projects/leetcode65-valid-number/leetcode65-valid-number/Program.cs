using System;
using System.Linq;

namespace leetcode65_valid_number
{
    class Program
    {
        public class Solution
        {
            public string ToNum(string s)
            {
                string num = String.Empty;

                s = s.Trim();
                string[] arr = s.Split('E');
                int LastZeroCountInPart1 = 0;
                foreach (char ch in arr[0].Reverse())
                {
                    if (ch == '0')
                        LastZeroCountInPart1++;
                    else
                    {
                        break;
                    }
                }

                bool isPart1Double = double.TryParse(arr[0], out var part1);
                int decimalDigitCountInPart1 = arr[0].IndexOf('.') == -1 ? 0 : arr[0].Length - 1 - arr[0].IndexOf('.');

                string newPart2 = arr.ElementAtOrDefault(1);
                bool isPart2Int = int.TryParse(newPart2, out var part2);
                if (arr.Length == 1)
                {
                    if (isPart1Double)
                        num = part1.ToString();
                }
                if (arr.Length == 2)
                {
                    if (part2 < 0 || part2 - decimalDigitCountInPart1 < 0)
                    {
                        if (isPart1Double && isPart2Int)
                            num = Decimal.Parse((part1 * Math.Pow(10, part2)).ToString(), System.Globalization.NumberStyles.Float).ToString();
                    }
                    else if (part2 - decimalDigitCountInPart1 >= 0)
                    {
                        num = part1.ToString().Replace(".", "") + new String('0', part2 - decimalDigitCountInPart1);
                    }

                }
                
                return num + new String('0', LastZeroCountInPart1);
            }
        }

        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string str;
            while ((str = Console.ReadLine()) != null)
            {
                Console.WriteLine(sol.ToNum(str));
            }
        }
    }
}