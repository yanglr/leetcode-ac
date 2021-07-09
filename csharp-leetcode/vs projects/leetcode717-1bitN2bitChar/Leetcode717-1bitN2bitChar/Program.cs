using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Leetcode717_1bitN2bitChar
{
    public class Solution
    {
        public bool IsOneBitCharacter(int[] bits)
        {
            bool IsTail0 = false;
            int len = bits.Length;
            if (len == 1)
                return true;
            if (bits.Last() == 0 && bits[len - 2] == 0)
                return true;
            int oneCounts = 0;
            for (int i = len - 2; i >= 0; i--)
            {                
                if (bits[i] == 1)
                    oneCounts++;
            }
            IsTail0 = (oneCounts & 1) != 0;  // there is bracket () for &

            return IsTail0;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
        }
    }
}
