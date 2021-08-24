#include <algorithm>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;  // 用栈存每一个字符在原串中的index
        st.push(-1);
        int len = s.size();
        int maxLen = 0;
        for (int i=0; i<len; i++)
        {            
            int topIndex = st.top();
            // 此处的topIndex != -1 相当于不加-1前的 !st.empty()
            if (topIndex != -1 && s[st.top()] == '(' && s[i] == ')') /* 匹配就出栈(并计算更新最大有效长度), 不匹配则入栈。 */
            {
                st.pop();
                maxLen = max(maxLen, i - st.top());
            }
            else st.push(i);
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