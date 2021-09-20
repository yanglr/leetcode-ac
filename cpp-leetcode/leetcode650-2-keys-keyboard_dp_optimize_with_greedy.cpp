#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, INT_MAX); // dp[i]: 得到i个A的最少操作次数
        dp[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= i; j++)
            {
                if (i % j != 0) continue;
                int k = i / j;
                dp[i] = min(dp[i], dp[k] + 1 + (j - 1));
                break; /* 用贪心思想优化 */
            }          
        }
        return dp[n];
    }
};

// Test
int main()
{
    Solution sol;
    int n = 10000;
    auto res = sol.minSteps(n);
    cout << res << endl;

    return 0;
}