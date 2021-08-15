#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        /* 思路: 从长字符串的开头开始找长度和模式串长度相同的子串，判断是否equal，直到模式串尾部与长字符串尾部对齐 */
        int len = needle.size();
        if(haystack.size() < len)
            return -1;
        int gap = haystack.size() - len;
        for(int i = 0; i <= gap; i++)
        {
            string sub = haystack.substr(i, len);
            if(sub == needle)
                return i;
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