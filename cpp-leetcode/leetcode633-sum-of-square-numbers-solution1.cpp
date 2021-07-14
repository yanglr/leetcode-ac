#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 0; c - 2 * i * i >= 0; i++)
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