#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int lCount = 0, rCount = 0;
        for (auto& ch : s)
            if (ch == '(') lCount++;
            else if (ch == ')') {
                if (lCount == 0) rCount++;
                else lCount--;
            }

        dfs(s, 0, "", 0, lCount, rCount) ;
        return res;
    }
    /* s: 原字符串, start pos: 表示枚举到哪个字符了, path: 字符串删完之后剩下的字符串, count: 当前左括号数量-右括号数量的差值是多少,
       l: 当前还能删除多少左括号, r: 当前还能删除多少右括号 */
    void dfs(string& s, int startPos, string path, int count, int lCount, int rCount) {
        if (startPos == s.size()) {
            if (!count) res.push_back(path);
            return;
        }

        if (s[startPos] != '(' && s[startPos] != ')') /* 根据题意: 只能删掉左右括号, 原字符串中的非括号的字符需要全部留下 */
            dfs(s, startPos + 1, path + s[startPos], count, lCount, rCount) ;
        else if (s[startPos] == '(') {
            // 双指针技巧统计连续相等的字符
            int k = startPos;
            while (k < s.size() && s[k] == '(') k++;
            lCount -= k - startPos; // k-startPos: 当前连续的左括号数量, 先删掉它们
            for (int i = k - startPos; i >= 0; i-- ) {
                if (lCount >= 0) dfs(s, k, path, count, lCount, rCount) ;
                path += '('; // 回溯: 加回来删除的1个括号
                count++;
                lCount++;
            }
        } else if (s[startPos] == ')') {
            int k = startPos;
            while (k < s.size() && s[k] == ')') k++;
            rCount -= k - startPos; // k-startPos: 当前连续的右括号数量, 先删掉它们
            for (int i = k - startPos; i >= 0; i--) {
                if (count >= 0 && rCount >= 0) dfs(s, k, path, count, lCount, rCount) ; /* count >= 0: 需要保证字符串的任意前缀中左括号数量>=右括号数量 */
                path += ')'; // 回溯: 加回来删除的1个括号
                count--;
                rCount++;
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    string s = "(a)())()";
    auto res = sol.removeInvalidParentheses(s);
    for (auto& str : res)
        cout << str << endl;

    return 0;
}