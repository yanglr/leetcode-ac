#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        // 情形1: 全大写
        bool isAllUpclass = false;
        int upClassCount = 0;
        for (auto ch : word)
        {
            if (isLowclass(ch)) break;
            else upClassCount++;
        }
        isAllUpclass = upClassCount == len;
        // 情形2: 全小写
        bool isAllLowclass = false;
        int lowClassCount = 0;
        for (auto ch : word)
        {
            if (isUpclass(ch)) break;
            else lowClassCount++;
        }
        isAllLowclass = lowClassCount == len;
        // 情形3: 首字母大写, 其他字母小写
        bool isOnlyFirstCharUpclass = false;
        int lowClassCount2 = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (isLowclass(word.front())) break;                
            if (i > 0 && isLowclass(word[i]))  lowClassCount2++;          
        }        
        isOnlyFirstCharUpclass = (lowClassCount2 == len - 1);
        return (isAllUpclass || isAllLowclass || isOnlyFirstCharUpclass);
    }
    
    bool isUpclass(char ch)
    {
        return (ch >= 'A' && ch <= 'Z');
    }
    bool isLowclass(char ch)
    {
        return (ch >= 'a' && ch <= 'z');
    }
};

// Test
int main()
{
    Solution sol;
    string str = "Leetcode";
    auto res = sol.detectCapitalUse(str);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}