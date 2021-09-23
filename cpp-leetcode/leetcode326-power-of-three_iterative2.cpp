#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0 || n == INT_MAX) return false; /* 2147483647的数字之和是46, 不是3的倍数, 自然不是3的次方 */
        while (n > 0 && (n % 3) == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 45;
    auto res = sol.isPowerOfThree(n);
    cout << (res == true ? "True" : "False") << endl;
    
    return 0;
}