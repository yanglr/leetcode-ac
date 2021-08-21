#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 方法: 回溯/dfs
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return {{}};
        const int len = nums.size();
        vector<vector<int>> res; 
        vector<int> curSet;
        res.push_back({});  /* 空集必然是其中一个子集 */
        for (int i = 1; i <= len; i++)
            dfs(nums, i, 0, curSet, res);
        return res;
    }

    void dfs(const vector<int>& nums, int len, int startPos, vector<int>& curSet, vector<vector<int>>& res)
    {
        if (len == curSet.size())
        {
            res.push_back(curSet);
            return;
        }

        for (int i = startPos; i < nums.size(); i++)
        {
            curSet.push_back(nums[i]);         // Choose
            dfs(nums, len, i+1, curSet, res);  // Explore
            curSet.pop_back();                 // Un-choose/Clean up state
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3 };
    auto res = sol.subsets(nums);

    return 0;
}