public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        List<int> lst = new List<int>();
        foreach(int n in nums)
        {
            lst.Add(n);
        }
        lst.Sort((x,y) => -x.CompareTo(y));  /* 对list从大到小排序 */

        return lst[k-1];
    }
}

// Test
void test()
{
    Solution sol = new Solution();
    int[] nums = {3,2,1,5,6,4};
    int k = 2;
    int res = sol.FindKthLargest(nums, k);
    System.Console.WriteLine(res);
}

test();