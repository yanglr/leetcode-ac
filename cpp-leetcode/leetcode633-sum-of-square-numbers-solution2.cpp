#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (long i = 0; c - 2 * i * i >= 0; i++)
        {
            int diff = c - i * i;
            if (IsPerfectSquare(diff))
                return true;
        }

        return false;
    }

    bool IsPerfectSquare(int num)
    {
        double sq1 = sqrt(num);
        int sq2 = (int)sqrt(num);
        if (fabs(sq1 - (double)sq2) < 10e-10)
            return true;
        
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