#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        int sum = 0;
        int pre2BeforeLast = 0;
        int pre1BeforeLast = 1;

        for (int i = 2; i < n + 1; i++)
        {
            sum = pre2BeforeLast + pre1BeforeLast;
            pre2BeforeLast = pre1BeforeLast;
            pre1BeforeLast = sum;
        }
        
        return sum;
    }
};

// Test
int main()
{
    int n = 9;
    Solution sol;
    printf("%d", sol.fib(n));

    return 0;
}