#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long l = 0;
        auto r = (long long)sqrt(c);        
        while (l <= r)
        {
            long long sum = l * l + r * r;
            if (sum == c) return true;
            
            if (sum < c) l++;
            else r--;
        }

        return false;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 666;
    bool res = sol.judgeSquareSum(n);

    cout << (res == true ? "true" : "false") << endl;

    return 0;
}