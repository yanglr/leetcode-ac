#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        while (label > 1)
        {
            res.push_back(label);
            getParent(label);                    
        }
        res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
    void getParent(int& num)
    {
        int levelIdx = 0;
        int copy = num;
        while (copy > 1)
        {
            copy /= 2;
            levelIdx++;
        }
        bool isRev = levelIdx % 2 == 1; 
        int preLevelIdx = levelIdx - 1;
        bool isPreRev = !isRev;
        int preLevelMin = 1 << preLevelIdx;
        vector<int> preLevel;     
        for (int i = preLevelMin; i < 2*preLevelMin; i++)
            preLevel.push_back(i);          
        if (isPreRev) reverse(preLevel.begin(), preLevel.end());
        int half = num / 2;           
        int halfIndex = find(preLevel.begin(), preLevel.end(), half) - preLevel.begin();
        num = preLevel[preLevelMin - 1 - halfIndex];        
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