#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0) return 1.0;        
        if (N >= K + W - 1) return 1.0;
        if (N < K) return 0.0;
        // dp[i] = (1/w) * (dp[i - 1] + ... + dp[i - w])
        double dp[K + W]; // 最大能达到的点数是 K+W-1
        fill(dp, dp + K + W, 0.0);
        double prob = 1.0 / W;
        dp[0] = 1.0;
        double sum = 1.0;
        for (int i = 1; i < K + W; i++)
        {
            dp[i] = prob * sum;
            if (i < K) sum += dp[i];
            if (i - W >= 0) sum -= dp[i - W];
        }
        double res = 0.0;
        for (int i = K; i <= N; i++)
            res += dp[i];
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int N = 21, K = 17, W = 10;
    auto res = sol.new21Game(N, K, W);
    cout << res << endl;

    return 0;
}