#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {        
        if (n < 2)
            return 0;
            
        vector<bool> isDelete(n, false);
        int max = (int)sqrt(n);
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isDelete[i])
                continue;
            count++;
            if (i > max)
                continue;
            for (int j = i * i; j < n; j += i)
                isDelete[j] = true;
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    auto result = sol.countPrimes(1001561);
    cout << result << endl;
    return 0;
}