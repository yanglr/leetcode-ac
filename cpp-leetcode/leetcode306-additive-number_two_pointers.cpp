#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        if (num == "")
            return false;

        int len = num.size();
        for (int i = 1; i < len; i++)   // 用双指针i, j分别作为substr{n-2}和substr{n-1}的开始位置
        {
            for (int j = i + 1; j < len; j++)
            {
                string s1 = num.substr(0, i);       // substr[0, i]
                string s2 = num.substr(i, j - i);   // substr[i, j]              
                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0'))
                    continue;  // 出现开头是字符0的情况, 不处理
                
                auto preNum = stoll(s1);
                auto curNum = stoll(s2);
                auto nextNum = preNum + curNum;
                
                auto combinedStr = s1 + s2 + to_string(nextNum);
                while (combinedStr.size() < num.size())          // 继续前移
                {
                    preNum = curNum;
                    curNum = nextNum;
                    nextNum = preNum + curNum; // 迭代地使用递推关系
                    combinedStr += to_string(nextNum);
                }

                if (combinedStr == num)
                    return true;
            }
        }
        return false;   
    }
};

// Test
int main()
{
    Solution sol;
    string s = "199100199";
    auto res = sol.isAdditiveNumber(s);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}