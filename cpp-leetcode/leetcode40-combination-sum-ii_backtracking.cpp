#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// dfs
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // 先排序, 防止后面重复处理
        vector<int> curGroup;
        dfs(candidates, target, 0, 0, curGroup);
        return res;
    }
    void dfs(const vector<int>& candidates, int target, int startPos, int sum, vector<int>& curGroup)
    {
        if (target == sum)
        {
            res.push_back(curGroup);
            return;
        }
        if (sum > target) return;  /* 当前sum已经超出target了, 后面加入正数不可能=target了, 于是递归终止 */        
        for (int i = startPos; i < candidates.size(); i++)
        {
            /* 去重, 当目前子区间内第1个元素(index为0)以后的元素出现重复时, 需要去重处理 */
            if (i > startPos && candidates[i] == candidates[i-1]) continue;
            curGroup.push_back(candidates[i]);
            dfs(candidates, target, i+1, sum + candidates[i], curGroup);
            curGroup.pop_back();
        }
    }
};

// Test
int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution sol;
    auto res = sol.combinationSum2(candidates, target);
    
    return 0;
}