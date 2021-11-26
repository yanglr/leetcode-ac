#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        unordered_map<int, int> dict;
        dict[0] = 1;

        for (auto& x : nums)
        {
            auto curDict = dict;
            dict.clear();
            for (auto& kvp : curDict)
            {
                dict[kvp.first + x] += kvp.second;
                dict[kvp.first - x] += kvp.second;
            }
        }
        return dict[S];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    auto res = sol.findTargetSumWays(nums, target);
    cout << res << endl;

    return 0;
}