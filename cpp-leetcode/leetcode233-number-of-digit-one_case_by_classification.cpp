#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;  /* 0 <= n <= 10^9 */
        
        int curDigit;
        int count = 0;      // 记录1的数量
        long highDigt, lastDigit, weigh = 1; // weigh用来记录置1的位置处于个位、十位、百位、千位等...
        while (weigh <= n)  // weigh每次乘10相对于从低位向高位方向逐位移动，直到超过n时结束循环 
        {
            highDigt = n / (weigh * 10);  // 得到某一个位数置1后的商，即当前数之前的部分 
            lastDigit = n % weigh;        // 得到某一位数置1后的余数，即当前数之后的部分
            curDigit = (n / weigh) % 10;  // 当前置1的位置原来(置1之前)的数

            if (curDigit == 0)   // 当前位置的数字=0时 
                count += highDigt * weigh; 
            if (curDigit == 1)  // 当前位置的数字=1时 
                count += highDigt * weigh + lastDigit + 1;
            if (curDigit > 1)   // 当前位置的数字>1时
                count += (highDigt + 1) * weigh;

            weigh *= 10;
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 13;
    auto res = sol.countDigitOne(n);
    cout << res << endl;

    return 0;
}