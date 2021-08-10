#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
    int maxLen = 0;
    int start = 0;

public:
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1) return s;        
        for (int i = 0; i < s.size(); i++)
        {
            backTrack(s, i, i);      /* 原串长度为奇数时, 回溯back tracking开始 */
            backTrack(s, i, i + 1);  /* 原串长度为偶数时, 回溯开始 */
        }
        return s.substr(start, maxLen);
    }

    void backTrack(string s, int left, int right) {
        while(left >= 0 && right < s.length() && s[left] == s[right]) {
            if(right - left + 1 > maxLen) {  /* 发现新的更长回文串时, 更新全局变量startPos和maxLen */
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }
    }
};

// Test
int main()
{
    Solution sol;
    string s = "babad";
    auto res = sol.longestPalindrome(s);
    cout << res << endl;

    return 0;
}