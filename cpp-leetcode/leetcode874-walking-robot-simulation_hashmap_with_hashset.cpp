#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int d = 1; // N: {0, 1}
        unordered_map<int, unordered_set<int>> dict;
        for (const auto& obstacle : obstacles)
            dict[obstacle[0]].insert(obstacle[1]);
        int res = 0;
        for (int& c : commands)
        {
            if (c == -2) d = (d - 1 + 4) % 4;
            else if (c == -1) d = (d + 1) % 4;
            else
            {
                while (c--)
                {
                    int tx = x + dirs[d][0];
                    int ty = y + dirs[d][1];
                    if (dict.count(tx) && dict.at(tx).count(ty))
                        break;
                    x = tx;
                    y = ty;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> obstacles = {{2, 4}};
    vector<int> commands = {4, -1, 4, -2, 4};
    auto res = sol.robotSim(commands, obstacles);
    cout << res << endl;

    return 0;
}