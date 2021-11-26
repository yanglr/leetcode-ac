#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};    
public:
    int maxDistance(vector<vector<int>>& grid) {
        int N = grid.size();
        queue<pair<int, int>> q; // queue存储坐标值, 即 pair of {x, y}
        vector<vector<int>> d(N, vector<int>(N, 1000)); // 二维数组d[][]: 记录每个格子grid[i][j]的距离值
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 1)
                {
                    q.push(make_pair(i, j));
                    d[i][j] = 0;
                }            
        }
        while (!q.empty())
        {
            auto kvp = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = kvp.first + dx[i], newY = kvp.second + dy[i];
                if (newX < 0 || newX >= N || newY < 0 || newY >= N) // 越界了, 跳过
                    continue;

                if (d[newX][newY] > d[kvp.first][kvp.second] + 1) /* 如果从水域(值为0的格子)走到陆地(值为1的格子)或从陆地走到水域, 且新到达的位置之前没被访问过, 此时需要将其坐标加入队列, 并更新距离值d */
                {
                    d[newX][newY] = d[kvp.first][kvp.second] + 1; /* 当前格子的上下左右4个方向之一走一步恰好使得曼哈顿距离增加1 */
                    q.push(make_pair(newX, newY));
                }
            }
        }
        int res = -1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0 && d[i][j] <= 200) /* 挑出访问过的水域位置(值为0的格子), 并维护这些格子中距离值d的最大值 */
                    res = max(res, d[i][j]);
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> grid = 
    {
        {1, 0, 1}, 
        {0, 0, 0}, 
        {1, 0, 1}
    };
    auto res = sol.maxDistance(grid);
    cout << res << endl;

    return 0;
}