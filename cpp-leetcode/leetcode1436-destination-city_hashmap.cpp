#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> dict;
        string res;   
        for (auto& path : paths)
        {
            dict[path[0]] += -1;
            dict[path[1]] += 1; 
            // 记录 sum = 1的key
            for (auto kvp : dict)
            {
                if (kvp.second == 1) res = kvp.first; /* 无论何时都只有一个key为1的城市 */
            }
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