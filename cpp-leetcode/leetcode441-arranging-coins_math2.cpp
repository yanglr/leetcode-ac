#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<iostream>
using namespace std;

typedef long long LL;
class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt((LL)8*n + 1) - 1) / 2;
    }
};

// Test
int main()
{
    Solution sol;
    int num = 10;
    auto res = sol.arrangeCoins(num);
    cout << res << endl;

    return 0;
}