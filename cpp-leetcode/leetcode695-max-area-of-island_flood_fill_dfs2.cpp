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
        /* 由于1 <= m, n <= 50, 故不需要判空 */
        int maxArea = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                maxArea = max(maxArea, dfs(grid, i, j));
        }
        return maxArea;
    }
    int dfs(vector<vector<int>>& grid, int x, int y)
    {
        // 判断当前传入坐标位置是否越界或是否为水域
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0)
            return 0;
        
        grid[x][y] = 0; // 已访问过的岛屿也修改为0，避免重复访问
        int area = 1; // 每个岛屿的面积为1
        for (int i = 0; i < 4; i++)
        {
            auto a = x + dx[i];
            auto b = y + dy[i];
            area += dfs(grid, a, b);
        }
        return area;
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