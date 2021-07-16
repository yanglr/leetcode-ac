#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;  // 跳过重复：当前项与相邻项相等时跳过
            for (int j = i + 1; j < n - 2; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;  // 跳过重复
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target)
                    {
                        vector<int> group{nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(group);

                        while (left < right && nums[left] == nums[left + 1])
                            left++;   // 左侧遇到重复，跳过
                        while (left < right && nums[right] == nums[right - 1])
                            right--;  // 右侧遇到重复，跳过
                        
                        // 继续找下一组满足条件的
                        left++;
                        right--;
                    }
                    else if (sum < target)
                        left++;
                    else
                        right--;
                }
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1,0,-1,0,-2,2 };
    int target = 0;
    auto res = sol.fourSum(nums, target);  /* debug下查看结果(二维数组) */
    
    return 0;
}