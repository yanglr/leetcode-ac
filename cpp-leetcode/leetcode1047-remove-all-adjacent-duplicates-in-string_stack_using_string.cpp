#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string noDupStr; /* 用字符串模拟栈 */
        for (char& ch : S)
        {
            if (!noDupStr.empty() && noDupStr.back() == ch)
                noDupStr.pop_back();
            else noDupStr.push_back(ch);
        }        
        return noDupStr;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abbaca";
    // 输出："ca"
    auto res = sol.removeDuplicates(s);
    cout << res << endl;

    return 0;
}