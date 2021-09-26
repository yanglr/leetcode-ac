#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        if(a == 0 || b == 0) return a | b;
        int sum = a^b; /* 对位相加, 不处理进位的部分(一个1, 一个0, 异或会得到1, 无进位; 两个0, 异或得到0; 两个1, 结果为0, 把进位丢给下面一行的&运算去处理) */
        unsigned int carry = a & b; /* 处理进位: 两个二进制数对位相加时, 同一个bit位都为1时才会产生进位 */
        return getSum(sum, carry << 1); 
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