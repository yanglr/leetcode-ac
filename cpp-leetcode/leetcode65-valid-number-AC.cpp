#include<algorithm>
#include<string>
#include <iostream>
#include <cctype>    /* 含有isdigit、isalpha等函数 */
using namespace std;  

class Solution {
public:
    // 有效数字格式如下
    // [+|-][数字][.][数字][e|E][数字]
    bool isNumber(string s) {
        bool success = false; // 最开始匹配失败
        int k = 0;
        if (s[k] == '+' || s[k] == '-') k++; // 过滤+|-
        while (isdigit(s[k]))  // 不管前面是否有符号+|-，一旦有数字，至此一定是匹配成功的
        {
            k++;
            success = true;
        }
        if (s[k] == '.') k++; // 过滤.
        while (isdigit(s[k]))  // 不管前面是否匹配成功，如果这里有数字，那么至此也一定是匹配成功的，如+.9或-9等
        {
            k++;
            success = true;
        }
        if (!success) return false; // 至此，底数已经匹配完成，如果匹配失败后面就不用再进行了
        // 下面判断是否有指数
        if (s[k] == 'e' || s[k] == 'E') 
        {
            k++, success = false; // 过滤 'e' 和 'E'
            if (s[k] == '+' || s[k] == '-') k++; // 过滤 +|-
            while (isdigit(s[k])) // 过滤数字
            {
                k++;
                success = true;                
            }
        }
        // 如何没有匹配到结尾了，说明是不合法数字
        if (k < s.length()) return false;
        // 如果到了最后一位，看是否匹配成功
        return success;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "95a5453";
    auto res = sol.isNumber(s);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}