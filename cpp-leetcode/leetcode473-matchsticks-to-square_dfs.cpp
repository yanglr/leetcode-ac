#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> _nums;
    vector<bool> used;
public:
    bool makesquare(vector<int>& bars) {
        if (bars.empty()) return false;
        used.resize(bars.size());
        _nums = bars;        
        int sum0 = accumulate(bars.begin(), bars.end(), 0);
        if (sum0 % 4 != 0) return false;
        sum0 /= 4; /* 如果有可能拼成正方形, 那么边长必为所有火柴长度之和的1/4 */
        sort(_nums.begin(), _nums.end(), greater<int>()); // 先从大到小排序, 降低dfs深度
        return dfs(0, 0, sum0, 0);
    }
    bool dfs(int startPos, /* 当前长度 */int cur, int edgeLen, /* 当前拼的是第几根, 共4根 */int count)
    {
        if (count == 3) return true;
        if (cur == edgeLen) return dfs(0, 0, edgeLen, count + 1); // 当前这条边拼好了, 接下来拼另一边
        for (int i = startPos; i < _nums.size(); i++)
        {
            if (used[i]) continue;
            if (cur + _nums[i] <= edgeLen)
            {
                used[i] = true;
                if (dfs(i+1, cur + _nums[i], edgeLen, count)) return true;
                used[i] = false; // 回溯/Unchoose                
            }   
            if (cur == 0 || cur + _nums[i] == edgeLen) /* cur == 0: 第一根失败; 最后一根失败: cur + _nums[i] == edgeLen */
                return false;         
            while (i + 1 < _nums.size() && _nums[i] == _nums[i+1])
                i++;
        }
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {10, 6, 5, 5, 5, 3, 3, 3, 2, 2, 2, 2};
    auto res = sol.makesquare(nums);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}