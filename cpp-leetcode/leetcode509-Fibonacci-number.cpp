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

        vector<int> f(n+1); // f is an array here
        f[0] = 0;
        f[1] = 1;

        for (int i = 2; i < n + 1; i++)
        {
            f[i] = f[i-2] + f[i-1];
        }
        
        return f[n];
    }
};

// Below is testing
int main()
{
    int n = 9;
    Solution sol;
    printf("%d", sol.fib(n));

    return 0;
}