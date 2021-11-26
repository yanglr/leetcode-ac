#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {5, 1, 3, 1, 2, 3, 3};
    auto res = sol.sortArray(nums);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}