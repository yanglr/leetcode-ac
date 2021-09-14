#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 方法: 回溯/dfs
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {{}};
        const int len = nums.size();
        vector<vector<int>> res; 
        if (len > 1)
            sort(nums.begin(), nums.end());        
        res.push_back({});  /* 空集必然是其中一个子集 */
        vector<int> curSet;        
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
            /* 去重, 当目前子区间内第1个元素(index为0)以后的元素出现重复时, 需要去重处理 */
            if (i > startPos && nums[i] == nums[i - 1]) continue;            
            curSet.push_back(nums[i]);         // Choose
            dfs(nums, len, i+1, curSet, res);  // Explore
            curSet.pop_back();                 // Un-choose
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3 };
    auto res = sol.subsetsWithDup(nums);
    for (auto& row : res) // 遍历每一行
    {
        cout << "{";
        for (int i = 0; i < row.size(); i++) // 输出每一个元素
        {
            auto elem = row[i];
            if (row.size() >= 2 && i <= row.size() - 2)
                cout << elem << ", ";  
            if (i == row.size() - 1) cout << elem;
        }        
        cout << "}\n";
    }        

    return 0;
}