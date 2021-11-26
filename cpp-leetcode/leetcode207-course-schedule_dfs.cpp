#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    vector<int> visited;
    vector<vector<int>> next; // 邻接矩阵, 其中next[i]是第i门课的所有先修课程
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        next.resize(numCourses);  // 由于是二维矩阵, 如果结构有变化第一维需要resize
        for (auto& p : prerequisites)
            next[p[0]].push_back(p[1]);
        for (int i = 0; i < numCourses; i++)
        {
            if (dfs(i) == false) return false;
        }
        return true;
    }
    bool dfs(int cur)
    {
        if (visited[cur] == 1) return true;
        if (visited[cur] == 2) return false;  // 当前状态之前处理过, 现在又正在处理

        visited[cur] = 2;   // 2: 将当前结点标记为"正在处理"状态
        for (int& next : next[cur])
        {
            if (dfs(next) == false) return false;
        }
        visited[cur] = 1; // 一个node及其邻接的所有结点被处理完一次时, 将其标记为"已经访问过"

        return true;
    }
};

// Test
int main()
{
    Solution sol;
    int num = 2;
    vector<vector<int>> pres = {{1,0},{0,1}};
    auto res = sol.canFinish(num, pres);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}