#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n]; // dp数组 - dp[i][j]: 从位置(0, 0)走到位置(i, j)的unique path的数量
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1; /* 原点位置(0, 0)只有不动这一种走法, 对矩阵中间某个位置 dp[i][j] = dp[i-1][j] + dp[i][j-1] */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i >= 1) 
                    dp[i][j] += dp[i-1][j];
                if (j >= 1)
                    dp[i][j] += dp[i][j-1];
            }
        }
        return dp[m - 1][n - 1];
    }
};

// Test
int main()
{
    Solution sol;
    int m = 3;
    int n = 7;
    auto res = sol.uniquePaths(m, n);
    cout << res << endl;

    return 0;
}