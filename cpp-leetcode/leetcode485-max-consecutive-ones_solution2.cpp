#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        const int len = nums.size();
        int maxLen = INT_MIN;
        int count = 0;        
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 1)
                count++;
            else
            {
                maxLen = max(maxLen, count);
                count = 0;
            }
        }
        return max(maxLen, count);
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