#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        if (n <= 1) return n;
        return sqrt(n);
    }
};

// Test
int main()
{
    Solution sol;
    int n = 3;
    auto res = sol.bulbSwitch(89);
    cout << res << endl;

    return 0;
}