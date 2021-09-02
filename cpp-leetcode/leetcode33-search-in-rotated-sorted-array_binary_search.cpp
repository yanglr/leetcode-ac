#include <vector>
#include <iostream>
using namespace std;

/* 分情况的二分搜索 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0) return -1;
        int left = 0, right = n-1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            /* 比较 nums[right], nums[mid], nums[left], target 几处的值 */
            if (nums[mid] < nums[right]) // 包括mid在内的后半段有序
            {
                if (nums[mid] < target && nums[right] >= target) left = mid + 1;
                else right = mid - 1;
            } else   // 包括mid在内的前半段有序
                {
                    if (nums[left] <= target && nums[mid] > target) right = mid - 1;
                    else left = mid + 1;
                }
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int res = sol.search(nums, target);
    cout << res << endl;

    return 0;
}