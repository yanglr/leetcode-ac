#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

struct Cell {
    int h, x, y;
    bool operator< (const Cell& t) const
    {
        return h > t.h;
    }
};
class Solution {
public:
    int trapRainWater(vector<vector<int>>& H) {
        if (H.empty() || H[0].empty())
            return 0;
        int n = H.size();    // 行数
        int m = H[0].size(); // 列数
        priority_queue<Cell> heap;
        vector<vector<bool>> vis(n, vector<bool>(m)); // 访问状态
        for (int i = 0; i < n; i++) // 预处理每一行的第1个和最后一个格子
        {
            vis[i][0] = vis[i][m - 1] = true;
            heap.push({H[i][0], i, 0});
            heap.push({H[i][m - 1], i, m - 1});
        }
        for (int i = 1; i + 1 < m; i++) // 预处理每一列的第2个和倒数第2行的格子, 因为每一列的第1个和最后一个格子已经预处理过了
        {
            vis[0][i] = vis[n-1][i] = true;
            heap.push({H[0][i], 0, i});
            heap.push({H[n - 1][i], n - 1, i});
        }
        int res = 0;
        while (!heap.empty())
        {
            auto top = heap.top();
            heap.pop();

            res += top.h - H[top.x][top.y]; /* top.h - H[top.x][top.y]: 每一个格子能帮助接到的水量, ≥ 0 */
            int dx[4] = {0, 1, 0, -1};
            int dy[4] = {1, 0, -1, 0};
            for (int i = 0; i < 4; i++)
            {
                int newX = top.x + dx[i];
                int newY = top.y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY]) /* 没出界, 且没被访问过 */
                {
                    heap.push({max(H[newX][newY], top.h), newX, newY});
                    vis[newX][newY] = true;
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
    vector<vector<int>> nums = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    auto res = sol.trapRainWater(nums);
    cout << res << endl;

    return 0;
}