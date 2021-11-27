#include<vector>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> nums; // 存储原字符串中的数
        stack<char> ops; // 存储原字符串中的符号(含括号和+-)
        for (int i = 0; i < s.size(); i++)
        {
            auto c = s[i];
            if (c == ' ') continue; // 过滤空格
            if (isdigit(c))
            {
                int n = 0;
                int j = i;
                while (j < s.size() && isdigit(s[j]))
                    n = n*10 + (s[j++] - '0');
                i = j-1;
                nums.push(n);
            }
            else if (c == '(') ops.push(c);
            else if (c == ')')
            {
                while (ops.top() != '(')
                    myEval(nums, ops);
                ops.pop();
            }
            else 
            {
                if (i == 0 || s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')  // 特殊处理符号和正号
                    nums.push(0);                
                while (!ops.empty() && ops.top() != '(') /* 由于此题中运算符只有+或-, 故不需要比较不同运算符的优先级了(括号前面已经处理了) */
                    myEval(nums, ops);
                ops.push(c);
            }
        }
        while (!ops.empty()) myEval(nums, ops);
        return nums.top();
    }
    void myEval(stack<int>& nums, stack<char>& ops)
    {
        if (ops.empty()) return;
        int res;
        
        auto b = nums.top();
        nums.pop();
        int a = 0;
        if (nums.size() > 0)
        {
            a = nums.top();
            nums.pop();
        }
        auto c = ops.top();
        ops.pop();

        if (c == '+') res = a + b;
        else if (c == '-') res = a - b;
        nums.push(res);
    }
};

// Test
int main()
{
    Solution sol;
    // string s = "(1+(4+5+2)-3)+(6+8)"; //"-2+ 1";
    string s = "1-(-2)"; //"-2+ 1";
    auto res = sol.calculate(s);
    cout << res << endl;

    return 0;
}