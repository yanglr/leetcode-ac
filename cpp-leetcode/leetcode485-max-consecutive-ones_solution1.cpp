#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        const int len = nums.size();
        int maxLen = 0;
        int curCount = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 1)
                curCount++;
            else curCount = 0;
            if (curCount > maxLen) maxLen = curCount;
        }
        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,1,0,1,1,1};
    auto res = sol.findMaxConsecutiveOnes(nums);
    cout << res << endl;

    return 0;
}