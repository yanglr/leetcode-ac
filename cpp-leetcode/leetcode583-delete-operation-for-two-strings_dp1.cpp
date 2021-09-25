#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 501)); /* 按照题意"给定单词的长度不超过500", 故最多删除次数不会超过500, 
        初始化为 INT_MAX/2也行, /2 避免后面代码中的+1时导致整型溢出 */
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        
        word1.insert(word1.begin(), '#'); /* 或者写城成 word1 = '#' + word1; */
        word2.insert(word2.begin(), '#');
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i] == word2[j])
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
                else
                {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                }
            }            
        }        
        return dp[m][n];
    }
};

// Test
int main()
{
    Solution sol;
    string str1 = "sea";
    string str2 = "eat";
    auto res = sol.minDistance(str1, str2);
    cout << res << endl;

    return 0;
}