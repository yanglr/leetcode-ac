#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        int shift = k % len;
        
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + shift);
        reverse(nums.begin() + shift, nums.end());        
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);

    for (int num : nums)
        cout << num << endl;

    return 0;
}