#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1]; // dp[i]: 凑成金额 i 的组合方式的总数量
        fill(dp, dp + amount + 1, 0);
        dp[0] = 1; // 可以使用一个tets case测试出来
        for (int& coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] = dp[i - coin] + dp[i]; /* 当前面值的硬币, 如果选它接下来处理总金额 i-coin, 如果不选它继续处理总金额i */
            }
        }
        return dp[amount];        
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