#include<bits/stdc++.h>
using namespace std;

class Solution {
public:    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> opt(n+2, 0);    /* base case: opt[n] = 0; 于是opt[n]和opt[n+1] 都应该初始化为0 */
        for (int i = n - 1; i >= 0; i--)
        {
            opt[i] = max(opt[i+1], opt[i+2] + nums[i]);
        }
        
        return opt[0];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,1};
    auto res = sol.rob(nums);
    cout << res << endl;

    nums = {2,7,9,3,1};
    res = sol.rob(nums);
    cout << res << endl;

    return 0;
}