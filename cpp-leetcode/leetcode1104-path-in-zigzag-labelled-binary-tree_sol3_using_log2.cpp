#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int levelIdx;
        int start, end; // 用来记录当前层的第1个和最后1个结点的值
        vector<int> res;        
        levelIdx = log2(label);
        start = 1 << levelIdx;
        end = (1 << (levelIdx + 1)) - 1;
        int pos, dir;        
        dir = levelIdx & 0x01; // levelIdx是奇数时 dir = 1(从右到左), 否则是0(从左到右)
        pos = dir ? label - start : end - label;        
        while (levelIdx)
        {
            start = 1 << levelIdx;
            end = (1 << (levelIdx + 1)) - 1;
            
            if (dir) res.push_back(start + pos);
            else res.push_back(end - pos);
            
            dir = 1 - dir; // 翻转: 0 => 1 或 1 => 0
            pos >>= 1;
            levelIdx--;
        }        
        res.push_back(1);        
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