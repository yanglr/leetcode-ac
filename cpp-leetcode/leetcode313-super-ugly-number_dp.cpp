#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        int k = primes.size();
        vector<int>p(k,0);       /* p数组放有每个质数 2, 3, 5...等的指针, 一开始都是0 */

        vector<int>results({1});

        for (int i=0; i<n-1; i++)
        {
            int next = INT_MAX;
            for (int j=0; j<k; j++)
                next = min(next, primes[j] * results[p[j]]);
            for (int j=0; j<k; j++)
            {
                if (next == primes[j] * results[p[j]])
                    p[j]++;
            }
            results.push_back(next);
        }

        return results.back();
    }
};

// Test
int main()
{
    Solution sol;
    int n = 12;
    vector<int> primes = {2, 7, 13, 19};
    auto res = sol.nthSuperUglyNumber(n, primes);
    cout << res << endl;
    
    return 0;
}