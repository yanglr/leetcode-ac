#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        // 二分搜索
        int l = 0, r = x;
        while (l < r)
        {
            auto mid = (l + (long long)r + 1)/2;
            // check(性质): t^2 <= x
            if (mid <= x/mid) /* 防止溢出 */
                l = mid;
            else r = mid - 1;
        }
        return l;  // 或 r, 循环结束时 l = r
    }
};

// Test
int main()
{
    Solution sol;
    int num = 666;
    auto res = sol.mySqrt(num);
    cout << res << endl;

    return 0;
}