#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 先排序, 然后 a < b < c, 对应指针为 i,j,k, 固定k (k一开始=len-1, 最后k>=2), 剩下两个数用双指针找
        int len = nums.size();
        if (len < 3) return 0;
        sort(nums.begin(), nums.end());
        int groupCount = 0;
        for (int k = len - 1; k >= 2; k--)
        {
            int i = 0;
            int j = k - 1;
            while (i < j)
            {
                if (nums[i] + nums[j] > nums[k])
                {
                    groupCount += j - i;  /* 对于每一趟(k确定时): 只要出现第1次满足要求的, 则只要j对应的数还在i对应数的右侧, 就可以继续统计。当 j = i+1时只要1组, 于是该情形下共有j-i组。最后把每一趟的组合数相加 */
                    j--;
                }
                else i++;
            }
        }
        return groupCount;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 2, 3, 4};
    auto res = sol.triangleNumber(nums);
    printf("%d ", res);
    return 0;
}