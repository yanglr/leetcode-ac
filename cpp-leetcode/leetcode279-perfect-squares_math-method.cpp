#include<iostream>
#include<cmath>
using namespace std;

/* 解题思路见题解 <https://leetcode-cn.com/problems/perfect-squares/solution/shu-xue-fa-bu-shi-yong-dong-tai-gui-hua-ddm33/> */
class Solution {
public:
    int numSquares(int n) {
        while (n % 4 == 0)
            n /= 4;

        if (n % 8 == 7)
            return 4;   // (path 1)

        for (int i = 0; i * i <= n; i++)
        {
            int r = (int)sqrt(n - i * i);
            if (i * i + r * r == n)
            {
                if (i == 0 || r == 0)
                    return 1;           // (path 2)

                return 2;   // (path 3)
            }
        }

        return 3;   // (path 4)
    }
};

// Test
int main()
{
    Solution sol;
    int k = 12;
    int res = sol.numSquares(k);
    cout << res << endl;

    return 0;
}