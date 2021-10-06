#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();
        int count = 0;
        int dx[2] = {0, 1};
        int dy[2] = {1, 0};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0) continue;

                count += 4;
                for (int k = 0; k < 2; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                    {
                        count -= 2;
                    }
                }
            }
        }
        return count;
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