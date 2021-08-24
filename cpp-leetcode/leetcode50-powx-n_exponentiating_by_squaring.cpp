#include <algorithm>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

/* 快速幂(Exponentiation by squaring, 平方求幂) */
class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0 && n == 0)
            return 1;
        if (x == 1 && n == INT_MIN)
            return 1;
        
        long N = abs(n);  /* 使用long, 防止整型溢出 */
        if (n < 0)
            x = 1.0 / x;
        
        double res = 1.0;
        for (; N > 0; N >>= 1)  // 指数exponent每次折半，进行迭代
        {
            if ((N % 2) == 1)   // 分奇偶两种情况处理
                res *= x;
            x *= x;             // 底数base每次求平方 => base^2
        }
        return res;
    }
};
// Test
int main()
{
    Solution sol;

    double x = 2.10000;
    int n = -3;
    auto res = sol.myPow(x, n);
    cout << res << endl;

    x = 0.999999999;
    n = -2147483648;
    res = sol.myPow(x, n);
    cout << res << endl;
    
    return 0;
}