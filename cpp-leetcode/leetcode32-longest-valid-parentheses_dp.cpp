#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int len = s.size();
        vector<int> dp(len, 0);  // dp[0] = 0
        for (int i = 1; i < len; i++)
        {
            if (s[i] == ')')
            {
                if (s[i-1] == '(')
                {
                    int prePartLen = i >= 2 ? dp[i-2] : 0;
                    dp[i] = prePartLen + 2;                    
                }
                else if(s[i-1] == ')')
                {
                    int splitIndex = i - 1 - dp[i-1]; 
                    if (splitIndex >= 0 && s[splitIndex] == '(')
                    {
                        int prePartLen = splitIndex >= 1 ? dp[splitIndex-1] : 0;
                        dp[i] = prePartLen + dp[i-1] + 2;
                    }
                }
                maxLen = max(maxLen, dp[i]);
            }
        }
        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    string s = ")()())";
    auto res = sol.longestValidParentheses(s);
    cout << res << endl;

    return 0;
}