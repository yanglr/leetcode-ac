#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int m = text1.size();
        const int n = text2.size();
        text1 = '#' + text1;
        text2 = '#' + text2;
        int dp[m + 1][n + 1];
        for (auto& row : dp)
            fill(row, row + n, 0);
        for (int i = 1; i <= m; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i++)
            dp[0][i] = 0;
        
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (text1[i] == text2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[m][n];
    }
};

// Test
int main()
{
    Solution sol;
    string str1 = "abcdecgdagkdgd";
    string str2 = "efgedsgded";
    auto res = sol.longestCommonSubsequence(str1, str2);
    cout << res << endl;

    return 0;
}