#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size() - k];   /* 最后1个数(index是len-1)是第1大，而不是第0大。于是第k大的数的index的 len-1-(k-1) = len - k */
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 3,2,1,5,6,4 };
    int k = 2;
    auto res = sol.findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}