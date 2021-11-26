#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // dp[i][j]: 用前i种硬币组成amount j的方法数量
        //dp[i][j] = dp[i-1][j] + dp[i][j-coins[i]]
        //dp[i][0] = 1
        //dp[n][amount]
        int n = coins.size();
        int dp[n + 1][amount + 1];
        for (auto& row : dp)
            fill(row, row + amount + 1, 0);
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                dp[i][j] += dp[i - 1][j];
                if (j >= coins[i - 1])
                    dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[n][amount];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    auto res = sol.change(amount, coins);
    cout << res << endl;

    return 0;
}