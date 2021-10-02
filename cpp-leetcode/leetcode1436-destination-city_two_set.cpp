#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> startSet;
        unordered_set<string> endSet;
        for (auto& path : paths)
        {
            startSet.insert(path[0]);
            endSet.insert(path[1]);
        }
        string res;        
        for (auto& city : endSet)
        {
            if (startSet.count(city) == 0)
                res = city;
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<string>> paths = {{"London","New York"},{"New York","Lima"},{"Lima","Sao Paulo"}};
    auto res = sol.destCity(paths);
    cout << res << endl;

    return 0;
}