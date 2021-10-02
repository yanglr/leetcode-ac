#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res;
        long N = num;     // 预处理: 将精度提升到int64, 防止大整数溢出
        if (N == 0) return "0";
        unordered_map<int, char> dict
        {
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'a'},
            {11, 'b'},
            {12, 'c'},
            {13, 'd'},
            {14, 'e'},
            {15, 'f'}
        };
        if (N < 0) N = N + 0x100000000; /* 负数的补码: 其数字范围就是0到UINT_MAX(2^31-1), 即为16^8-1。
        这里+ 0x100000000是为了将任意一个负数转换到正数范围内(且不影响计算结果), 理论上±2^32均可, 但我们后面的迭代需要是正数, 于是选择+0x100000000。 */
        while (N > 0)
        {
            long lastDigit = N % 16;
            N /= 16;
            res = dict[lastDigit] + res;
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int num = -1;
    auto res = sol.toHex(num);
    // 预期结果是 ffffffff
    cout << res << endl; /* 用Dev C++运行正常 */ 

    return 0;
}