#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int len = nums.size();
        vector<int> preProd(len);
        preProd[0] = 1;
        for (int i = 1; i < len; i++)
            preProd[i] = preProd[i-1] * nums[i-1];
        
        // 接下来求rightProduct
        int right = 1;
        for (int i = len-1; i >= 0; i--)
        {
            preProd[i] *= right;
            right *= nums[i];
        }
        return preProd;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {3, 2, 8, 5};
    auto res = sol.productExceptSelf(nums);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}