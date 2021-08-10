#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int len = s.size();
        // 先固定中心点 i
        for (int i = 0; i < len; i++)
        {
            // 枚举长度是奇数的情况
            int l = i - 1, r = i + 1;
            while (l >= 0 && r <= len && s[l] == s[r])
            {
                l--, r++;
            }
            if (res.size() < r - l - 1)
            {
                res = s.substr(l + 1, r - l - 1);
            }

            // 枚举长度是奇数的情况
            l = i, r = i + 1;
            while (l >= 0 && r <= len && s[l] == s[r])
            {
                l--, r++;
            }
            if (res.size() < r - l - 1)
            {
                res = s.substr(l + 1, r - l - 1);
            }            
        }
        return res;
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