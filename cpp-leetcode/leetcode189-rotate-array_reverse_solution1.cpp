#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int shift = k % n;

        // 翻转前 n - shift 个数.
        // Index i (0 <= i < n - shift) 会变成 n - shift - i.
        reverse(nums.begin(), nums.begin() + n - shift);
        
        // 翻转末尾 shift 个数.
        // Index n - shift + i (0 <= i < shift) 会变成 n - i.
        reverse(nums.begin() + n - shift, nums.begin() + n);
        
        // 翻转所有数
        // Index i (0 <= i < n - shift) 会变成 n - (n - shift - i) = i + shift.
        // Index n - shift + i (0 <= i < shift) 会变成 n - (n - i) = i.
        reverse(nums.begin(), nums.begin() + n);        
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