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
        if(n == 1)
            return "1";    // f(1) = 1
        
        string res = "1";  // f(1) = 1, 作为迭代的初始值放入到结果中
        for(int i=0; i<n-1; i++)
        {
            string currentCombinedStr = "";
            char curFirstChar = res[0];    // 存放当前分片的第一个字符
            int currentCharCount = 0;            
            for(char ch : res)             // 将当前的字符与当前分片的第一个字符比较
            {
                if(ch == curFirstChar)
                    currentCharCount += 1;
                else {         
                    // 出现新的字符时，把已处理的连续相同字符的信息插入到结果字符串中
                    currentCombinedStr.append(to_string(currentCharCount));
                    currentCombinedStr.push_back(curFirstChar);

                    curFirstChar = ch;
                    currentCharCount = 1;
                }
            }

            // 把末尾连续相同字符的信息插入到结果字符串中(对末尾一段字符来说，不会再有新的字符了)
            currentCombinedStr.append(to_string(currentCharCount));
            currentCombinedStr.push_back(curFirstChar);            
            res = currentCombinedStr; // 将结果用作下一轮循环的初始值
        }

        return res;
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