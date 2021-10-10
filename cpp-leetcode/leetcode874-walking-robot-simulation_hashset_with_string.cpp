#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obSet; // 压缩信息: 以"x-y"的形式存储障碍物的坐标信息
        for (auto& obp : obstacles) obSet.insert(pathStr(obp[0], obp[1]));
        int x = 0, y = 0;
        int idx = 0;       // idx: 此时落在方向数组中的index, index in direction array
        int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0}; /* 第1个元素表示向北的方向, 机器人一开始面向北方, 4个依次表示北、东、南、西(0,1,2,3) */
        int res = 0; // 当前机器人所在位置与原点之间的欧式距离的平方
        for (auto& c : commands)
        {
            if (c == -2) idx = (idx + 3) % 4;       // 左转1次(相当于右转3次), +3后%4 防止数组越界
            else if (c == -1) idx = (idx + 1) % 4;  // 右转1次, +1后%4 防止数组越界
            else
            {
                for (int i = 0; i < c; i++)
                {
                    int a = x + dx[idx];
                    int b = y + dy[idx];
                    if (obSet.count(pathStr(a, b))) break;
                    x = a; // 从临时变量中更新
                    y = b;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
    string pathStr(int x, int y)
    {
        return to_string(x) + '#' + to_string(y);
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