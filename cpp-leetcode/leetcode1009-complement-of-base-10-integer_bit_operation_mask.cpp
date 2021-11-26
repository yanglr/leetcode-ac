#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        unsigned mask = INT_MAX;
        // unsigned mask = ~0;    /* 也能这样写 */
        
        /* 由于存储 n 时, 有32个bit, 其高位有不少的0. 故此处按位取反时~n 的高位会产生很多不必要的1 */
        while (n & mask) mask <<= 1; /* 这里的目标是把mask末尾与结果相关的bit位清零, 循环结束时mask的形式是111...00  */
        return ~n & (~mask); 
    }
};

// Test
int main()
{
    Solution sol;
    int num = 5;
    auto res = sol.bitwiseComplement(num);
    cout << res << endl;

    return 0;
}