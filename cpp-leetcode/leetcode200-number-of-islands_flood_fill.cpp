#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    vector<vector<char>> M;
    int rows;
    int cols;    
public:
    int numIslands(vector<vector<char>>& grid) {
        M = grid;
        rows = grid.size();
        cols = grid[0].size();

        int count = 0;       
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
                count += dfs(r, c);            
        }
        return count;            
    }

    int dfs(int r, int c) /* dfs: return能形成的连通岛屿的数量(上下左右四连通) */
    {    
        if (r < 0 || c < 0 || r == rows || c == cols)
            return 0;
        if (M[r][c] == '0')
            return 0;
        
        M[r][c] = '0';  /* 将当前格子标记为: visited, 并检查当前格子的上下左右4个位置。下次遇到1(地)就继续向前, 下次遇到0(水, 表示已到尽头)就结束  */

        dfs(r - 1, c);  // 选择上方相邻位置前进
        dfs(r + 1, c);  // 选择下方相邻位置前进
        dfs(r, c - 1);  // 选择左侧相邻位置前进
        dfs(r, c + 1);  // 选择右侧相邻位置前进

        return 1; 
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    auto res = sol.numIslands(grid);
    cout << res << endl;

    return 0;
}