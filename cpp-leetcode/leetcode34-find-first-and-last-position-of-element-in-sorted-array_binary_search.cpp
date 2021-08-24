#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        if (nums.empty()) return res; /* 处理输入: nums = {} */
        
        const int len = nums.size();
        int left = 0, right = len - 1;
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target)
            return res;
        
        res[0] = right;
        left = right, right = nums.size();

        while (left < right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else right = mid;
        }
        res[1] = left - 1;

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    auto res = sol.searchRange(nums, target);
    for (auto &pos : res)
        cout << pos << " ";    

    return 0;
}