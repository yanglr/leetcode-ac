#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string stk; // 用string模拟栈
        for (auto& c: s) {
            stk += c;
            if (stk.size() >= 3 && stk.substr(stk.size() - 3) == "abc")
            {
                for (int i = 0; i < 3; i++)
                    stk.pop_back();
            }
        }
        return stk.empty();
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abcabcababcc";
    auto res = sol.isValid(s);
    cout << (res ? "True" : "False") << endl;
    
    return 0;
}