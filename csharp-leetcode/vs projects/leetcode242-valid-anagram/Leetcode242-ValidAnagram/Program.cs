using System;
using System.Collections.Generic;

namespace Leetcode242_ValidAnagram
{
    public class Solution
    {
        public bool IsAnagram(string s, string t)
        {
            if (s.Length != t.Length)
                return false;

            int[] counts = new int[26];
            for(int i = 0;i < s.Length;i++)
            {
                counts[s[i] - 'a']++;
                counts[t[i]-'a']--;
            }

            foreach (var count in counts)
                if (count != 0)
                    return false;

            return true;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            string str;
            while ((str = Console.ReadLine())!=null)
            {
                string[] strArr = str.Split(' ');
                if (strArr.Length < 2)
                    return;

                string s = strArr[0], t = strArr[1];
                bool result = sol.IsAnagram(s, t);
                Console.WriteLine(result);
            }
        }
    }
}
