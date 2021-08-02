#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        /* 题意:
        * 强弱的规则有两条:
        * 1、该row的1的数量比较少
        * 2、遇到与该row中1的数量相同的，row index越小, 该row越弱
        */
        vector<int> res;
        unordered_map<int, int> dict; // map: row index -> count of 1 (or sum)
        for (int i = 0; i < mat.size(); i++)
        {
            vector<int> row = mat[i];
            dict[i] = count(row.begin(), row.end(), 1);
        }
        // k: 倒计数的计数器, 出来1个就-1
        // 越靠前, 越小, 于是直接取靠前的即可.
        auto cmp = [](pair<int, int> x, pair<int, int> y)
        {
            if (x.second == y.second)
                return x.first > y.first;
            else return x.second > y.second;  /* 小顶堆, 这里y代表顶部值 */
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (pair<int, int> kvp : dict)
        {
            q.push(kvp);
        }

        while (!q.empty() && k > 0)
        {   
            res.push_back(q.top().first);
            q.pop();
            k--;                
        }

        return res;
    }
};

// Test
int main()
{   
    Solution sol;
    vector<vector<int>> mat = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
    int k = 3;
    auto res = sol.kWeakestRows(mat, k);
    for (auto index : res)
        cout << index << endl;
    
    return 0;
}