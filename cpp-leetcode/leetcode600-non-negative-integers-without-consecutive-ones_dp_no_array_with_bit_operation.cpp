#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findIntegers(int num) {      
        int res = 0;
        int preBit = 0; // 记录当前的digit是否为1
        int k = 30;     // 指针k, 从二进制数的末位开始向前移动
        while (k >= 0)
        {
            if (num & (1 << k)) // 从低位向高位扫描, 判断第k位是否为1
            {
                res += getF(k);
                if (preBit) return res; // 出现了连续的1, 直接返回res
                preBit = 1; // 当前digit是1, 于是将preBit更新为1
            }
            else preBit = 0;

            --k;
        }
        return res + 1; // 算上 num 本身
    }
    int getF(int k)  /* 计算f(k) */
    {
        int f_i_1 = 1, f_i_2 = 2, f_i_3 = 3;
        if (k == 0) return f_i_1;
        if (k == 1) return f_i_2;      
        for (int i = 2; i <= k; i++)  /* 已知f1, 求fn总共需要迭代n-1+1-maxIndexGap(2) = n-2 次 */
        {
            // f_n = f_n-1 + f_n-2
            f_i_3 = f_i_2 + f_i_1;
            f_i_1 = f_i_2;
            f_i_2 = f_i_3;
        }
        return f_i_3;         
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