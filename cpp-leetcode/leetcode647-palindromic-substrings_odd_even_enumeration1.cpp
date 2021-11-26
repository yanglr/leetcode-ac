#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        const int N = s.size();
        for (int i = 0; i < N; i++) // 枚举中心位置的index
        {
            // 枚举回文子串长度为奇数的情况
            for (int j = i, k = i; j >= 0 && k < N; j--, k++) /* 指针j(代表L)和k(代表R)是当前回文串的左右边界 */
            {
                if (s[j] != s[k])
                    break;
                count++;
            }
            // 偶数情况
            for (int j = i, k = i + 1; j >= 0 && k < N; j--, k++) /* 指针j(代表L)和k(代表R)的起点距离为1 */
            {
                if (s[j] != s[k])
                    break;
                count++;
            }
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abc";
    auto res = sol.countSubstrings(s);
    cout << res << endl;

    return 0;
}