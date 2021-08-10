#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        s = " " + s, p = " " + p;  /* 为方便计算, 从第1个字符开始统计, 故需在开头补上空格 */
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        f[0][0] = true;
        for (int i = 0; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (j + 1 <= m && p[j + 1] == '*')
                    continue;  /* 如果一个字母(比如a)的后一个字符是*, 那么a不能单独看待，应与*看成是一个整体，所以需要跳过 */
                if (i && p[j] != '*')
                {
                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
                }
                else if (p[j] == '*')
                {
                    /* 不需要判断 j >= 2, 英文如果有*出现, 那它之前必然至少还有1个字符 */
                    f[i][j] = f[i][j - 2] || i && (f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.'));
                }
            }

        return f[n][m];
    }
};

// Test
int main()
{
	Solution sol;
    string s = "aab", p = "c*a*b";
	auto res = sol.isMatch(s, p);
    cout << (res == true ? "true" : "false") << endl;
        
    return 0;
}