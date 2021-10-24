#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string exp(num.length() * 2, '\0'); // 模拟string buffer
        dfs(num, target, 0, exp, 0, 0, 0, res);
        return res;
    }
private:
    void dfs(const string& num, const int target, // input
             int pos, string& exp, int len, long prev, long curr, // state
             vector<string>& res) // output
    {
        if (pos == num.length())
        {
            if (curr == target)
                res.push_back(exp.substr(0, len));
            return;
        }

        long n = 0;
        int s = pos; // 初始处理到的字符的位置
        int l = len;       // len: 初始表达式的长度, L处放操作符op
        if (s != 0) len++; // 放数字
        while (pos < num.size())
        {
            n = n * 10 + (num[pos] - '0'); // 直接用数字算, 不做字符串转换
            if (num[s] == '0' && pos - s > 0)
                break; // 0xx... invalid number
            if (n > INT_MAX)
                break; // too long
            exp[len++] = num[pos++]; // 维护一个expression, 时间复杂度为O(1)的拷贝
            if (s == 0)
            {
                dfs(num, target, pos, exp, len, n, n, res);
                continue;
            }
            exp[l] = '+';
            dfs(num, target, pos, exp, len, n, curr + n, res); // 使用len, 省去了拼接 curExp + op + num.substr(pos, l) 的过程
            exp[l] = '-';
            dfs(num, target, pos, exp, len, -n, curr - n, res);
            exp[l] = '*';
            dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, res);
        }
    }
};

// Test
int main()
{
    Solution sol;
    string num = "1325";
    int targetNum = 31;
    auto res = sol.addOperators(num, targetNum);
    for (auto& str : res)
        cout << str << endl;

    return 0;
}