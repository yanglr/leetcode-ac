#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    bool visited[100][100];
    int dir[4][2] = {{-1, 0},{0, -1},{1, 0},{0, 1}};
    int row;
    int col;
    int res = 0;
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        row = grid.size();
        col = row == 0 ? 0 : grid[0].size();
        if (col == 0)
            return 0;
        
        for (auto& theRow : visited)
            fill(theRow, theRow + col, false);
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                visited[i][j] = true;
                if (grid[i][j] == 0)
                    continue;

                for (int k = 0; k < 4; k++)
                {
                    int newX = i + dir[k][0];
                    int newY = j + dir[k][1];
                    if (isInRange(newX, newY) && grid[newX][newY] == 0)
                        res++;
                    else if (!isInRange(newX, newY))
                        res++;
                }
            }
        }
        return res;
    }
    bool isInRange(int i, int j)
    {
        return i >= 0 && j >= 0 && i < row && j < col;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    auto res = sol.islandPerimeter(grid);
    cout << res << endl;

    return 0;
}