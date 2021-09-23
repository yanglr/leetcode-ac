#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double x = log10(n)/log10(3);
        if(int(x) == x) return true;
        return false;
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