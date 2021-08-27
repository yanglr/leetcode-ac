#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        if(n < 2)
        {
            return 0;
        }
        else {
            int count = 0;
            for (int i = 2; i * i < n; i++)
            {
                if (isPrime[i])
                {
                    for (int j = i; i * j < n; j++)  // Use j to record times(倍数).
                    {
                        isPrime[i*j] = 0;
                    }
                }
            }

            for (int i = 2; i < n; i++)
            {
                if (isPrime[i] == 1)
                    count++;
            }

            return count;
        }
    }
};

// Test
int main()
{
    Solution sol;
    auto result = sol.countPrimes(100156150);
    cout << result << endl;
    return 0;
}