#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int len = nums.size();   // len = n-1
        int expectSum = len*(len+1)/2; // (n-1)*n/2
        int sum = 0;
        for (int i = 0; i < len; i++)
            sum += nums[i];
             
        return (expectSum - sum);
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    auto res = sol.missingNumber(nums);
    cout << res << endl;

    return 0;
}