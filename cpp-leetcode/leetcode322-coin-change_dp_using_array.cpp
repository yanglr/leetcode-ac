#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount + 1]; // dp[i]: 凑成金额 i 所需的 最少的硬币个数
        fill(dp, dp + amount + 1, 10001);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) /* 填充 dp[1] ~ dp[amount] */
        {
            for (auto& coin : coins)
            {
                if (i < coin) continue; // 当前面值大于要凑的总额
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    auto res = sol.coinChange(coins, amount);
    cout << res << endl;

    return 0;
}