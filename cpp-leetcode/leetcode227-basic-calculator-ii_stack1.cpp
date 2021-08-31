#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 特点: 没有括号, 使用栈来做
class Solution {
public:
    int calculate(string s) {
        string temp;
        for (auto ch : s)
        {
            if (ch != ' ')
                temp.push_back(ch);
        }
        s = "+" + temp;

        int len = s.size();
        vector<int> nums;

        for (int i=0; i < len; i++)
        {
            if (s[i] == '+' || s[i] == '-')
            {
                int j = i+1; // 找出"+200"这种结构中的数字
                while (j < len && isdigit(s[j])) j++; // 循环结束时, j多跑了1位
                int endPos = j-1;
                int num = stoi(s.substr(i+1, endPos-(i+1)+1));                                
                if (s[i] == '+') nums.push_back(num);
                else nums.push_back(-num);
                i = endPos;
            }
            else if (s[i] == '*' || s[i] == '/')
            {
                int j = i+1; // 找出"*100"这种结构中的数字
                while (j < len && isdigit(s[j])) j++;
                int endPos = j-1;
                int num = stoi(s.substr(i+1, endPos-(i+1)+1));  
                if (s[i] == '*')                     
                    nums.back() = nums.back() * num;
                else nums.back() = nums.back() / num;             
                i = endPos;                
            }
        }
        int sum = 0;
        for (int i=0; i < nums.size(); i++) sum += nums[i];
        return sum;
    }
};

// Test
int main()
{
    Solution sol;
    string s = " 3+5 / 2 ";
    auto res = sol.calculate(s);
    cout << res << endl;

    return 0;
}