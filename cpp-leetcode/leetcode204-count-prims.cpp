#include<algorithm>
#include<vector>
#include<cmath>
#include <numeric>
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
            isPrime[0] = isPrime[1] = 0;
            for (int i = 2; i < int(sqrt(n)) + 1; i++)
            {
                if (isPrime[i])
                {
                    //isPrime[i*i:n:i] = [0]*((n-1-i*i)//i + 1)
                    for (int k = i*i; k < n; k += i)
                    {
                        isPrime[k] = 1;
                    }
                    
                }
                
            }
            return accumulate(isPrime.begin(), isPrime.end(), 0);;
        }
    }
};
        // if n < 2:
        //     return 0
        // else:
        //     isPrime = [1]*n  # isPrime = not deleted
        //     isPrime[:2] = [0]*2

        //     for i in range(2, int(math.sqrt(n)) + 1):
        //         if isPrime[i]:
        //             isPrime[i*i:n:i] = [0]*((n-1-i*i)//i + 1)
        // return sum(isPrime)            