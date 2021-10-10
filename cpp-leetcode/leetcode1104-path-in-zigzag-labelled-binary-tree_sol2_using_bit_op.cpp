#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;   
        int i = 2; 
        int level = 0;    // 计算label所在层的level index
        while (i <= label)
        {
            i *= 2;
            level++;
        }        
        res.push_back(label);        
        while (level > 0)
        {
            int level_min = 1 << level;
            int level_max = (1 << (level + 1)) - 1;
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