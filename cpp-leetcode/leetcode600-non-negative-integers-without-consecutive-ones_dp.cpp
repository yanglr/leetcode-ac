#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> f(32);
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; i++)
            f[i] = f[i - 1] + f[i - 2];
        string numStr = toBinary(n);
        int res = 0;
        for (int i = 0; i < numStr.size(); i++) {
            if (numStr[i] == '0') /* 选出numStr[i] = '1'的digit */
                continue;
            res += f[numStr.size() - i - 1];
            if (i != 0 && numStr[i - 1] == '1')
                return res;
        }
        return res + 1;
    }
    string toBinary(long n)  /* 非负整数转二进制表示的字符串 */
    {
        string res = "";
        while (n > 0)
        {
            char r = n % 2 + '0';
            res.push_back(r);     /* 放进去的结果会导致低位在前, 高位在后 */
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 666;
    auto res = sol.findIntegers(n);
    cout << res << endl;

    return 0;
}