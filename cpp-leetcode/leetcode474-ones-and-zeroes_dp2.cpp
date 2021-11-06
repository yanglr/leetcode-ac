#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        auto newDp = dp;
        for (string& str : strs)
        {
            int zeros = 0, ones = 0;
            for (char& ch : str)
            {
                if (ch == '0')
                    zeros++;
                else ones++;
            }
            for (int i = zeros; i <= m; i++)
            {
                for (int j = ones; j <= n; j++)
                    newDp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
            dp = newDp; // 更新一下供下一次迭代使用
        }
        return newDp[m][n];
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    int m = 5;
    int n = 3;
    auto res = sol.findMaxForm(strs, m, n);
    cout << res << endl;

    return 0;
}