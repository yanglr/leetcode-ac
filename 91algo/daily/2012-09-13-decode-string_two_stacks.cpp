#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        deque<int> numStack;
        deque<string> strStack;
        string resStr;

        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            if (isdigit(ch))
            {
                int digit = ch - '0';
                while (i < n - 1 && isdigit(s[i + 1]))
                {
                    digit = digit * 10 + s[i + 1] - '0';
                    i++;
                }
                numStack.push_front(digit);
            }
            else if (ch == '[')
            {
                strStack.push_front(resStr);
                resStr.clear();
            }
            else if (ch == ']')
            {
                string tmp = strStack.front();
                strStack.pop_front();
                int repeatCount = numStack.front();
                numStack.pop_front();
                for (int j = 0; j < repeatCount; j++)
                    tmp.append(resStr);

                resStr = tmp;
            }
            else resStr.push_back(ch);  // 直接取出来放进结果字符串中
        }
        return resStr;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "2[abc]3[cd]ef";
    auto res = sol.decodeString(s);
    // 期望的结果: "abcabccdcdcdef"
    cout << res << endl;  
    
    return 0;
}