using System;
public class Solution
{
    public int SingleNumber(int[] nums)
    {
        int a = 0, b = 0;
        for(int i = 0;i < nums.Length;i++)
        {
            b = (b ^ nums[i]) & ~a;
            a = (a ^ nums[i]) & ~b;
        }
        return b;
    }
}

void test()
{
    var sol = new Solution();
    var input = new int[] { 2,2,3,2 };
    Console.WriteLine (sol.SingleNumber(input));
    
    input = new int[] { 0,1,0,1,0,1,99 };
    Console.WriteLine(sol.SingleNumber(input));
}

test();