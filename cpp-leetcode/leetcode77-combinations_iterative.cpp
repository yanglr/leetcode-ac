#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> curGroup;
        // 迭代法: 先加入一个最小的满足条件的组合, 然后用对各位微调生成更多
        for (int i = 1; i <= k; i++)
            curGroup.push_back(i);
        
        while (true)
        {
            int i = k-1;
            while (i >=0 && curGroup[i] == i+1 + n-k)
                i--;
            if (i == -1) // 取到最大的数
                break;
            curGroup[i]++;
            for (int j = i+1; j<k; j++)
            {
                curGroup[j] = curGroup[j-1] + 1;
            }
            res.push_back(curGroup);
        }
        
        return res;
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