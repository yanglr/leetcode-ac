using System;
using System.Collections.Generic;
using System.Linq;
using System.Diagnostics;

namespace ZJNUoj1259_LuckyNum
{
    class Program
    {
        public class Solution
        {
            public const Int64 N = 100000000; 
            public string GetKthLuckyNum(int n)
            {
                Dictionary<Int64, string> luckyNums = new Dictionary<Int64, string>();
                int count = 0;
                for (Int64 i = 0; i <= N; i++)
                {
                    if (IsLuckyNum(i.ToString()))
                    {
                        count++;
                        luckyNums.Add(count, i.ToString());
                    }
                }

                bool canGetValue = luckyNums.TryGetValue(n, out var result);
                return result;
            }

            private bool IsLuckyNum(string str)
            {
                int count4 = str.Count(f => f == '4');
                int count7 = str.Count(f => f == '7');

                return count4 + count7 == str.Length;
            }
        }

        static void Main(string[] args)
        {
            string str;
            while ((str = Console.ReadLine()) != null)
            {
                Stopwatch stopWatch = new Stopwatch();
                stopWatch.Start();

                int k = int.Parse(str);
                var sol = new Solution();
                Console.WriteLine(sol.GetKthLuckyNum(k));

                stopWatch.Stop();
                TimeSpan ts = stopWatch.Elapsed;
                string elapsedTime = $"{ts.Hours:00}:{ts.Minutes:00}:{ts.Seconds:00}.{ts.Milliseconds/10:00}";
                Console.WriteLine($"RunTime{elapsedTime}");
            }
        }
    }
}
