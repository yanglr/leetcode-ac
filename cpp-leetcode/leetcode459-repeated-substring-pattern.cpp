#include<algorithm>
#include<string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // 如果可由子串重复形成, 那子串的长度必然能整除原串长度, 根据对称性, 为了减少重复计算, 从字符串中间出发遍历即可 */
        int len = s.size();
        for (int i = len/2; i >= 1; i--)
        {
            if (len % i == 0)
            {
                int count = len / i;
                string combineStr = "";
                string subStr = s.substr(0, i);
                for (int k = 0; k < count; k++)
                    combineStr += subStr;
                
                if (combineStr == s) return true;
            }
        }
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "abcabcabcabc";
    auto res = sol.repeatedSubstringPattern(str);
    cout << (res == true ? "True" : "False") << endl; 

    return 0;
}