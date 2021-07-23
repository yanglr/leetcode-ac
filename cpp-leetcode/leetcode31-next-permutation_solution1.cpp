#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,1,5};
    sol.nextPermutation(nums);

    for (int num : nums)
        cout << num << endl;

    return 0;
}