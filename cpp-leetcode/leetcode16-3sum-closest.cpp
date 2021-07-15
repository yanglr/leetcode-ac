#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest = nums[0] + nums[1] + nums[2];
        int gap = abs(closest - target);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {  /* 注意循环的上界, 需要给后两个数留位置 */
            int left = i + 1, right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                int curGap = abs(sum - target);
                if (gap > curGap) {
                    gap = curGap;
                    closest = sum;
                }
                if (sum < target)
                    left++;
                else right--;
            }
        }
        return closest;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    auto res = sol.threeSumClosest(nums, target);
    cout << res << endl;

    return 0;
}