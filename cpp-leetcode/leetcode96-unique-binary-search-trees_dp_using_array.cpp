#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        fill(dp, dp + n + 1, 0);
        dp[0] = 1; // root == null的树, 只有1棵

        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k <= i-1; k++)
            {
                dp[i] += dp[k] * dp[i - 1 - k];
            }
        }
        return dp[n];
    }
};

// Test
int main()
{
    Solution sol;
    int n = 3;
    auto res = sol.numTrees(n);
    cout << res << endl;

    return 0;
}