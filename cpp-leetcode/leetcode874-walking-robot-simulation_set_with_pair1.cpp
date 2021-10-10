#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int x = 0, y = 0;
        int curIdx = 0;
        const int comLen = commands.size();
        int res = 0;
        set<pair<int, int>> obSet;
        for (int i = 0; i < obstacles.size(); ++i)
        {
            obSet.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
        for (int i = 0; i < comLen; ++i)
        {
            if (commands[i] == -2) // 取模是为了防止数组越界
                curIdx = (curIdx + 3) % 4;
            else if (commands[i] == -1)
                curIdx = (curIdx + 1) % 4;
            else {
                for (int j = 0; j < commands[i]; j++)
                {
                    int nx = x + dx[curIdx];
                    int ny = y + dy[curIdx];
                    if (obSet.count(make_pair(nx, ny)) == 0)
                    {
                        x = nx;
                        y = ny;
                        res = max(res, x * x + y * y);
                    }
                    else break;
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