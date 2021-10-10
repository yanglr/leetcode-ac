#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int level = 0;   // 计算label所在层的level index
        while (pow(2, level + 1) <= label)
            level++;        
        res.push_back(label);        
        while (level > 0)
        {
            int level_min = pow(2, level);
            int level_max = pow(2, level + 1) - 1;
            label = (level_min + level_max - label) / 2;
            res.push_back(label);
            
            level--;
        }
        reverse(res.begin(), res.end());        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    auto res = sol.pathInZigZagTree(12);
    for (auto x : res)
        cout << x << " ";

    return 0;
}