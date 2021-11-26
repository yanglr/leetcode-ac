#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int N = cost.size();
        vector<int> dp(N); /* 题意: 2 <= cost.length <= 1000 */
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < N; i++)
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);
        return min(dp[N-2], dp[N-1]);
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> costs = {10, 15, 20};
    auto res = sol.minCostClimbingStairs(costs);
    cout << res << endl;
    
    return 0;
}