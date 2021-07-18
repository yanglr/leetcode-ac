#include <string>
#include <iostream>
// #include <algorithm>
using namespace std;

/* 
主体思路: 以已知a4=1211, 来求a5为例。
首先将不同字符间(用虚线)划开进行分片，即 1|2|11，分别统计各个分片中连续相同的字符数即可。
*/
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";  // f(1) = 1
        
        while (n > 1) {
            string curStr = "";
            for (int i = 0; i < res.size(); i++) {
                int count = getRepeatCount(res.substr(i));  // 截取从当前字符到末尾的子串
                curStr += to_string(count);
                curStr.push_back(res[i]);

                // 跳过重复的字符, 共处理一次即可
                i = i + count - 1;
            }
            n--;  // 总共需要迭代 n-1 次

            res = curStr;  // 将结果用作下一轮循环的初始值
        }
        return res;
    }

    /* 得到字符串 str 中第一个分片中连续相等数的重复个数，例如: "111221" 返回 3, "2" 返回 1 */
    int getRepeatCount(string str) {
        int count = 1;
        char same = str[0];
        for (int i = 1; i < str.size(); i++) {
            if (same == str[i]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 9;    
    string res = sol.countAndSay(n);
    cout << res << endl;

    return 0;
}