#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> table(N, vector<int>{});
        vector<vector<int>> paths;
        vector<int> q; /* q: 数组模拟队列, 存 LIS 中的数 */
        int i, j, k, res = 0;
        for (auto& num : nums)
        {
            i = lower_bound(q.begin(), q.end(), num) - q.begin();
            k = 1;
            if (i > 0)
            {
                j = upper_bound(table[i - 1].begin(), table[i - 1].end(), -num) - table[i - 1].begin();
                k = paths[i - 1].back() - paths[i - 1][j];
            }
            table[i].push_back(-num);

            if (i == q.size())
            {
                q.push_back(num);
                paths.push_back({0, k});
            }
            else
            {
                q[i] = num;
                paths[i].push_back(paths[i].back() + k);
            }
        }
        return paths.back().back();
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    auto res = sol.findNumberOfLIS(nums);
    cout << res << endl;

    return 0;
}