#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int len = nums.size();
        int res = nums.front();
        for (int i = 1; i < len; i++)
            res = res ^ nums[i];  /* 基于异或^运算来做成对抵消 */
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    printf("%d ", sol.singleNumber(nums));
    return 0;
}