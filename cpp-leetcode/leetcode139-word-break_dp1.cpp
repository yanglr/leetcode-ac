#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /** 题意: 1 <= s.length <= 300, 故不需要判空 */
        const int len = s.size();
        bool dp[len + 1];
        dp[0] = true;
        fill(dp + 1, dp + len + 1, false);        
        for (int i = 0; i < len; i++) /* 双指针i和j */
        {
            for (int j = i + 1; j <= len; j++)
            {
                string subs = s.substr(i, j - i); /* 对于字符串s中[i:j]范围内的子串subs, 都去判断一下dp[i]是不是true以及subs在不在数组wordDict中。 */
                if (find(wordDict.begin(), wordDict.end(), subs) != wordDict.end() && dp[i])
                    dp[j] = true;
            }
        }
        return dp[len];
    }
};

// Test
int main()
{
    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    // 预期输出: true
    auto res = sol.wordBreak(s, wordDict);
    cout << (res == true ? "true" : "false");

    return 0;
}
