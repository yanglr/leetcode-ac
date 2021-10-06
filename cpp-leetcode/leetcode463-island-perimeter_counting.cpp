#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 由于1 <= row, col <= 100, 故不需要判断空
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;
        int conn = 0; // 每个格子的neighbor数量的总和

        for (int y = 0; y < m; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (grid[y][x] == 1)
                {
                    area++;
                    if (y > 0 && grid[y - 1][x] == 1) conn++;     // 正上方的格子
                    if (y < m - 1 && grid[y + 1][x] == 1) conn++; // 正下方的格子
                    if (x > 0 && grid[y][x - 1] == 1) conn++;     // 正左方的格子
                    if (x < n - 1 && grid[y][x + 1] == 1) conn++; // 正右方的格子
                }                  
            }          
        }

        return area * 4 - conn;
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