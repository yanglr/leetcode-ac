#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int len = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());                          // 先进行排序(从小到大)
        if (nums.empty() || nums.front() > 0 || nums.back() < 0) /* 处理临界情况 */
        {
            return {};
        }

        for (int i = 0; i < len - 2; i++)
        {
            if (nums[i] > 0)
            {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) /* 注意此处的nums[i] == nums[i-1], 需要覆盖尽量多的case。当循环没到达尾部，且相邻位置出现相等的数组元素时, 跳过  */
            {
                continue;
            }

            int target = 0 - nums[i]; // a+b = -c
            int j = i + 1;
            int k = len - 1;

            while (j < k)
            {
                if (nums[j] + nums[k] == target)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j + 1]) /* 注意此处的 j<k 不能漏。当区间左侧相邻位置遇到相等的数时, 跳过 */
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k - 1]) /* 当区间右侧相邻位置遇到相等的数时, 跳过 */
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] < target)
                {
                    j++;
                }
                else k--;
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> input = {-1, 0, 1, 2, -1, -4}; // {0,0,0}
    vector<vector<int>> res = sol.threeSum(input);

    return 0;
}