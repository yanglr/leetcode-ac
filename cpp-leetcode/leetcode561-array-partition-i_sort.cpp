#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        const int len = nums.size();
        for (int i = 0; i <= len - 1; i += 2)
            sum += nums[i];
        return sum;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {6, 2, 6, 5, 1, 2};
    int res = sol.arrayPairSum(nums);
    cout << res << endl;

    return 0;
}