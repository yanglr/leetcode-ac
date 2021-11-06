#include<vector>
#include<numeric>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum0 = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        auto it = max_element(nums.begin(), nums.end());
        long long maxNum = *it;
        if (n * maxNum == sum0) /* 数组中最大数=数组平均数时不需要移动, 包含 n == 1 的case */
            return 0;

        auto it1 = min_element(nums.begin(), nums.end());
        long long minNum = *it1;

        return (sum0 - n * minNum);
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 7, 5};
    auto res = sol.minMoves(nums);
    cout << res << endl;

    return 0;
}