#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> curGroup;
        dfs(n, k, 1, curGroup);
        return res;
    }
    void dfs(int n, int k, int startNum, vector<int>& curGroup)
    {
        if (curGroup.size() == k) 
        {
            res.push_back(curGroup);
            return;
        }

        for (int i = startNum; i <= n; i++)
        {
            // 取到第1个, 放进 curGroup
            curGroup.push_back(i);
            // dfs取下一个
            dfs(n, k, i+1, curGroup);
            // clean up               
            curGroup.pop_back();         
        }
    }
};

// Test
int main()
{
    Solution sol;
    int n = 7, k = 5;
    auto res = sol.combine(n, k); /* 加断点到下一行进行debug, 可以看到结果 */    
    return 0;
}