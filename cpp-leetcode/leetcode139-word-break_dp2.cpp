#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// 更快的dp, 时间复杂度: O(N * M), N是字符串s的长度, M是数组wordDict的长度
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int len = s.size();
        bool dp[len + 1];
        dp[0] = true;
        fill(dp + 1, dp + len + 1, false);        
        for (int i = 1; i <= len; i++)
        {
            if (!dp[i - 1]) continue;     /* dp[i - 1]是false时, 是无法完成拆分的, 指针i跳到下一个index */
            for (auto& word : wordDict) /* 能执行到这, 说明子串s[0:i-1]都是能拆分的。遍历数组wordDict, 尝试从s中取出新的子串(这个子串的长度和当前循环的word相等, 即s[i-1:j]), 如果这个子串恰好与当前word相同, 那么子串s[0:j]也都是能拆分的。重复以上过程~ */
            {
                int j = i - 1 + word.size();
                if (j <= len && s.substr(i - 1, word.size()) == word)  /* 指针j也不能越界, 即j <= len */
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
