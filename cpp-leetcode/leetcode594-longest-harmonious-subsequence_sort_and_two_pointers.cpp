#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int L = 0;
        int r = 0;
        const int len = nums.size();
        int maxLen = 0;
        while (r < len)
        {
            while (nums[r] - nums[L] > 1)
                L++;
            if (nums[r] - nums[L] == 1)
                maxLen = max(maxLen, r - L + 1);
            r++;
        }
        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.findLHS(nums);
    cout << res << endl;

    return 0;
}