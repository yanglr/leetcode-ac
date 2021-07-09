using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode744_FindSmallestLetterGreaterThanTarget
{
    public class Solution
    {
        public char NextGreatestLetter(char[] letters, char target)
        {
            List<char> list = letters.ToList();
            list.Add(target);
            list.Sort((x, y) => x.CompareTo(y));
            if (list.LastOrDefault() <= target)
                return list.FirstOrDefault();
            return list.FirstOrDefault(x => x > target);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
