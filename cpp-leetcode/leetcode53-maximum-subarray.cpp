#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return nums[0];

        int maxSum = INT_MIN;
        int currentSum = 0;
        for(int i = 0; i<len; i++)
        {
            currentSum += nums[i];
            if(currentSum > maxSum)   /* 将最大和更新为当前和  */
                maxSum = currentSum;
            
            if(currentSum < 0)
                currentSum = 0;  /* 若currentSum=0，此时什么都不做，等价于置为0. */
        }

        return maxSum;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = sol.maxSubArray(nums);
    cout << res << endl;

    return 0;
}