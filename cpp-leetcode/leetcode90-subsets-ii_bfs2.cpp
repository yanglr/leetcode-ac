#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 方法: 回溯/dfs
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 1) return res;
        sort(nums.begin(), nums.end());
        vector<int> curSet;
        dfs(nums, 0, curSet, res);
        return res;
    }
    void dfs(vector<int>& nums, int startPos, vector<int>& curSet, vector<vector<int>>& res)
    {
        if (startPos == nums.size())
        {
            res.push_back(curSet);
            return;
        }
        curSet.push_back(nums[startPos]);
        dfs(nums, startPos + 1, curSet, res);
        curSet.pop_back();
        /* 跳过相同值 */
        while (startPos + 1 < nums.size() && nums[startPos + 1] == nums[startPos])
            startPos++;   
        dfs(nums, startPos + 1, curSet, res);     
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3};
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