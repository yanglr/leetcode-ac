#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<long> A(n+1);
        A[0] = 0;
        if(n >= 1) A[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0) A[i] = A[i/2];
            else A[i] = A[i/2] + A[i/2 + 1];
        }
        auto it = max_element(A.begin(), A.end());
        long res = *it;
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int N = 5;
    auto res = sol.getMaximumGenerated(N);
    cout << res << endl;

    return 0;
}