#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> part1(nums.begin(), nums.begin() + n);
        vector<int> part2(nums.begin() + n, nums.end());
        for (int i = 0; i < n; i++)
        {
            nums[2*i] = part1[i];
            nums[2*i + 1] = part2[i];
        }
        return nums;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    int k = 3;

    auto res = sol.shuffle(nums, k);
    for (auto &num : res)
        cout << num << endl;   

    return 0;
}