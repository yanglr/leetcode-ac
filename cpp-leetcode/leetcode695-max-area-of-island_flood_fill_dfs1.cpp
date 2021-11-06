#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {       
        m = grid.size();
        n = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int x, int y) /* G[i][j] == 1时才调用dfs */
    {
        int res = 1; // 把当前格子加进来
        grid[x][y] = 0; /* 加完之后就将用水(0)代替之前的陆地(1), 目的是避免重复访问。用这种方法就不需要使用visited数组记录状态了 */
        for (int i = 0; i < 4; i++)
        {
            auto a = x + dx[i];
            auto b = y + dy[i];
            if (a >= 0 && a < m && b >= 0 && b < n) // 确保没越界
            {
                if (grid[a][b] == 1)
                    res += dfs(grid, a, b); // 把连通块数累加一下
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
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}
    };
    auto res = sol.maxAreaOfIsland(grid);
    cout << res << endl;

    return 0;
}