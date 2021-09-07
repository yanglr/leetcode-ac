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

    int dfs(int r, int c)
    {    
        if (r < 0 || c < 0 || r == rows || c == cols)
            return 0;
        if (M[r][c] == '0')
            return 0;
        
        M[r][c] = '0';

        dfs(r - 1, c);  
        dfs(r + 1, c);  
        dfs(r, c - 1);  
        dfs(r, c + 1); 

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