#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        while (n > 0 && (n % 3 == 0)) /* 记住: 这里需用 while, 而不是if */
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