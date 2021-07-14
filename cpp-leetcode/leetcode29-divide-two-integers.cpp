#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        /*
        1、除法的本质是多次减法  
        2、用移位实现乘2以及除2的操作              
        */
        if (dividend == INT_MIN && divisor == -1) return INT_MAX; /* 临界情况 */
        long res = 0;
        long m = fabs(dividend), n = fabs(divisor);
        int sign;
        if((dividend < 0 && divisor < 0) || (dividend > 0 && divisor > 0))
            sign = 1;
        else sign = -1;

        while(m >= n)
        {
            long d = n, c = 1;   // 除数n的倍数d, 计数c
            while(m >= (d << 1))
            {
                d <<= 1;  // d=n*(2^i), 每次扩大2倍
                c <<= 1;  // c=2^i，与d同步加倍               
            }
            res += c;
            m -= d;            
        }

        return sign == 1 ? res : -res;
    }
};

// Test
int main()
{
    Solution sol;
    int m = 1314887, n = 13;
    auto res = sol.divide(m,n);
    cout << res << endl; 

    return 0;
}