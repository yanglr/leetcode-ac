#include<vector>
#include<array>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        unsigned int carry;
        while (b != 0) /* 把b先拿过去加一次, 后面用b存储每一次的进位值 */
        {
            carry = (a & b) << 1; /* 单独处理进位 */
            a ^= b;               /* 对位相加, 不处理进位的部分 */
            b = carry;
        }
        return a;
    }
};
