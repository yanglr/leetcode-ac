#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) 
    {
        int countMin = 0; // 未匹配上的左括号的最小数量，对应的策略是将*尽量用作右括号)
        int countMax = 0; // 未匹配上的左括号的最大数量, 对应的策略是将*尽量用作左括号(
        // 未匹配上的左括号的数量可以用区间[countMin, countMax]表示   

        for (auto& ch : s)
        {
            if (ch == '(')
            {
                countMin++;
                countMax++;
            }
            else if (ch == '*')
            {
                countMin--;
                countMax++;
            }
            else if (ch == ')')
            {
                countMin--;
                countMax--;
            }

            if (countMax < 0) return false;
            if (countMin < 0) countMin = 0;  // 没办法完全按对应的最佳策略进行, 让步一下, 用掉一个星号*          
        }
        /* 遍历完时, [countMin, countMax] ≥ 0, 最终要求左右括号平衡, 那么此区间需要包含一个 count = 0的状态, 那么countMin必须为0 */
        return countMin == 0;
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