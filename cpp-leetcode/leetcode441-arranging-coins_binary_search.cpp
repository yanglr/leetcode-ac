#include<algorithm>
#include<vector>
#include<cmath>
#include<unordered_set>
#include<iostream>
using namespace std;

using LL = long long;
class Solution {
public:
    int arrangeCoins(int n) {
        LL left = 0, right = (LL)n + 1;
        while (left < right)
        {
            LL mid = left + (right - left) / 2; // 防止整型溢出
            LL target = (mid + 1) * mid / 2;
            if (target <= n)
                left = mid + 1;
            else right = mid;
        }
        return left - 1;
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