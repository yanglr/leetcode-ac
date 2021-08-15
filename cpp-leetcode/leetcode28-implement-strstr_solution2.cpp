#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* 本解法是暴力法, 比较慢 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        const int lenN = needle.size();
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == lenN) return i;       /* 当for循环不给上界判断条件时, 如果短串needle能遍历到底, 循环结束时 j == lenN。
                                                如果加上界时,  j <= lenN - 1 */
                if (i + j == haystack.size())  /* 结束循环时, 最大公共子串长度 < needle长度, 不满足要求 */
                    return -1;
                if (needle[j] != haystack[i + j])  /* 持续考察等长区间 needle[0...j] 与 haystack[i..i+j], 比较前者的指针j 和后者的指针i+j 处的字符
                                                    是否相等, 不相等就结束循环, 看短的能不能一直跑到末尾 */
                    break;
            }
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "babad";
    string t = "ab";
    auto res = sol.strStr(s, t);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}