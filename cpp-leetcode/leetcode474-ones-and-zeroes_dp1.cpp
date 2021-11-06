#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (string& str : strs)
        {
            int zeros = 0, ones = 0;
            for (char& ch : str)
            {
                if (ch == '0')
                    zeros++;
                else ones++;
            }
            for (int i = m; i >= zeros; i--) /* 设置好边界: 数组不会越界, 同时当超过字符0、1的数量超过其容量m, n时, 更新dp数组时不考虑它们, 它们对dp表不会有任何影响。 */
            {
                for (int j = n; j >= ones; j--)
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
            }
        }
        return dp[m][n];
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