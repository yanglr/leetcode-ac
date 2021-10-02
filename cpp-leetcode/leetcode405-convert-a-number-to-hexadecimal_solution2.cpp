#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res;
        long N = num; 
        if (N == 0) return "0";
        string dict = "0123456789abcdef";
        if (N < 0) N = N + 0x100000000; 
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