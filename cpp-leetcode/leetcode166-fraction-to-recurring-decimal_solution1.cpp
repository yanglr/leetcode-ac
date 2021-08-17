#include <algorithm>
#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
/**
 * @Author: https://github.com/yanglr
 * @Date: 2021-08-17 17:32:27
 * @Title: LeetCode166. 分数到小数
 * @中文题目: 166. 分数到小数
 * @EnglishTitle: 166. Fraction to Recurring Decimal
 * @Alias: LC166 - 力扣166
 * @Tag: 数学
 * Created by 极客学长 on 2021-08-17.
*/
class Solution {
public:
    // 使用缩写: A: 分子numerator, D: 分母denominator
    string fractionToDecimal(int A, int D) {
        if (A == 0) return "0";
        string res;
        
        // 符号位
        int sign = 1;
        if ((A > 0 && D > 0) || (A < 0 && D < 0))
            sign = 1;
        else sign = -1;
        A = abs(A);
        D = abs(D);
        long beforeDot = A/D;
        if (sign == -1) res.push_back('-');        
        res.append(to_string(beforeDot));

        long rem = A%D;
        if (rem == 0) return res;
        else res.append(".");
        unordered_map<int, int> dict;  // 余数 -> 余数在结果字符串中的index
        // 没有除尽且暂时没发现"循环节"时一直loop
        while (rem != 0 && dict.find(rem) == dict.end())
        {
            dict[rem] = res.size();  // value -> index
            int quo = rem*10/D;
            res.push_back('0' + quo);
            rem = rem*10%D;
        }
        if (rem == 0) return res;
        // 遇到循环节, 循环终止的原因发现了第一个第2次出现的余数
        char firstRepChar = rem;
        int repStartIndex = dict[rem];
        res.insert(res.begin() + repStartIndex, '(');
        res += ")";

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int A = 4, D = 333;
    auto res = sol.fractionToDecimal(A, D);
    cout << res << endl;

    return 0;
}