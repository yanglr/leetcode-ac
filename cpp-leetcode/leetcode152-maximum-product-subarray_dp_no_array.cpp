#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];  /* 1 <= nums.length <= 2 * 10^4, -10 <= nums[i] <= 10 */
        int f = nums[0];    // f: 记录最大值f[i], g: 记录最小值g[i]
        int g = nums[0];
        const int N = nums.size();
        for (int i = 1; i < N; i++)
        {
            int a_i = nums[i];
            int fa = f*a_i;
            int ga = g*a_i;
            f = max(a_i, max(fa, ga));
            g = min(a_i, min(fa, ga));
            res = max(res, f);        // 更新最终的最大值
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, -2, 4};
    auto res = sol.maxProduct(nums);
    cout << res << endl;

    return 0;
}