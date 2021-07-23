#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while (L < R) {
            int M = (L + R) / 2;
            if (nums[M] < target) {
                L = M + 1;
            } else 
                R = M;
        }
        return (nums[L] < target) ? L + 1 : L;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;
    int res = sol.searchInsert(nums, target);
    cout << res << endl;

    return 0;
}