#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1) == 0;
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