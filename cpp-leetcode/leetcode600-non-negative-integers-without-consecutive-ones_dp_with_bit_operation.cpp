#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {
        int f[32];
        f[0] = 1;
        f[1] = 2;
        for (int i = 2; i < 32; ++i)
            f[i] = f[i - 1] + f[i - 2];
        int res = 0;
        int preBit = 0; // 记录当前的digit是否为1
        int k = 30;     // 指针k, 从二进制数的末位开始向前移动
        while (k >= 0)
        {
            if (num & (1 << k)) // 从低位向高位扫描, 判断第k位是否为1
            {
                res += f[k];
                if (preBit) return res; // 出现了连续的1, 直接返回res
                preBit = 1; // 当前digit是1, 于是将preBit更新为1
            }
            else preBit = 0;

            --k;
        }
        return res + 1; // 算上 num 本身
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