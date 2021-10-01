#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int M = grid.size();
        const int N = grid[0].size();
        int dp[M][N];
        for (auto& row : dp)
            fill(row, row + N, 0);
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[0][0];
                else if (i == 0)
                    dp[i][j] = dp[0][j - 1] + grid[0][j];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][0] + grid[i][0];
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }            
        }
        return dp[M - 1][N - 1];        
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}};
    auto res = sol.minPathSum(grid);
    printf("%d ", res);
    return 0;
}