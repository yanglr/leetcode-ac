#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int maxDiff = 0, minDiff = 0;
        // Diff 表示 左括号数量 - 右括号数量, maxDiff表示其最大值, minDiff表示其最小值
        for (int i = 0; i < s.length(); i++)
        {
            maxDiff += (s[i] == '(' || s[i] == '*') ? 1 : -1;
            minDiff += (s[i] == ')' || s[i] == '*') ? -1 : 1;
            if (maxDiff < 0) return false;
            minDiff = std::max(0, minDiff);
        }
        return minDiff == 0;
    }
};

//Test
int main()
{
    Solution sol;
    string str = "(*))";
    bool res = sol.checkValidString(str);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}