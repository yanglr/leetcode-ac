#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        const int len = nums.size();
        for (int i = 0; i < len - 2; i++)
        {
            if (nums[i] < nums[i + 1] + nums[i + 2])
                return nums[i] + nums[i + 1] + nums[i + 2];
        }            
        return 0;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 3, 4};
    auto res = sol.largestPerimeter(nums);
    printf("%d ", res);
    return 0;
}