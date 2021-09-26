#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        while (b != 0) /* 把b先拿过去与a相加(&运算求出进位值, 异或^求出和的不进位部分), 后面用b存储每一次的进位值 */
        {
            carry = (unsigned long)(a & b) << 1; /* 单独处理进位, unsigned long有时可以换成unsigned int */
            a ^= b;                              /* 对位相加, 不处理进位的部分 */
            b = carry;
        }
        return a;
    }
};

// Test
int main()
{
    Solution sol;
    int a = 10;
    int b = -3;
    auto res = sol.getSum(a, b);
    cout << res << endl;
    
    return 0;
}