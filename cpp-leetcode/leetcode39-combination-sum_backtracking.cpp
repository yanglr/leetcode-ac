#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// dfs
class Solution {
    vector<vector<int>> res;

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curGroup;
        dfs(candidates, target, curGroup, 0, 0);
        return res;
    }
    void dfs(vector<int> &candidates, int target, vector<int> &curGroup, int sum, int startPos)
    {
        if (sum > target)
            return;
        if (sum == target)
            res.push_back(curGroup);
        else
        {
            int curSum = sum;
            for (int i = startPos; i < candidates.size(); i++)
            {
                sum = curSum;                // 保证sum不受同层元素的影响
                sum = sum + candidates[i];
                curGroup.push_back(candidates[i]);
                dfs(candidates, target, curGroup, sum, i);
                curGroup.pop_back();
            }
        }
    }
};

// Test
int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    auto res = sol.combinationSum(candidates, target);
    
    return 0;
}