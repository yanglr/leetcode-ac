#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) return 1;
        /* 递归: f(n) = 2(n/2 + 1 - f(n/2)) */
        return n == 1 ? 1 : 2 * (n/2 + 1 - lastRemaining(n/2));
    }
};

// Test
int main()
{
    Solution sol;
    int n = 4;
    auto res = sol.lastRemaining(n);
    cout << res << endl;

    return 0;
}