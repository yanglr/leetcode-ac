#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long i = 0; c - 2 * i * i >= 0; i++)  /* 边界条件: 当i=2147482647(INT_MAX)时，如果用int，2 * i * i会越界，需改为 long */
        {
            double diff = c - i*i; /* 做一次循环，用目标和减去循环变量的平方，如果剩下的部分依然是完全平方，开方上取整=开方下取整 即可 */
            if ((int)(ceil(sqrt(diff))) == (int)(floor(sqrt(diff))))
                return true;
        }

        return false;        
    }
};

// Test
int main()
{
    Solution sol;
    int n = 666;
    bool res = sol.judgeSquareSum(n);

    cout << (res == true ? "true" : "false") << endl;

    return 0;
}