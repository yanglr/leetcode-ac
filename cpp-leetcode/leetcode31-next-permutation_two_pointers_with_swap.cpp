#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return;
        // 核心: 提升最后一个可以提升(与后一位连起来看是升序的)的数, 原数组中允许有重复的数. 使用双指针实现.        
        int i = len - 1;
        while (i > 0 && nums[i - 1] >= nums[i]) i--; /* 从后向前找第一个降序的位置i */
        if (i == 0)  // 从前到后是单调递减的, 已经是最大的排列数组
            reverse(nums.begin(), nums.end());
        else /* 从后向前, 找到了第一个降序对 nums[i-1] < nums[i], 此时i-1位置就是全局中第1处可以提升的 */
        {
            int j = i; /* 指针j从i处出发往后走, 每发现1个比nums[i-1]大的数就移动j。由于nums[i]~ nums[len - 1]是从前往后递减的, 找到那个恰好大于nums[i-1]的数时停下 */
            while (j < len && nums[j] > nums[i - 1]) j++;
            swap(nums[i - 1], nums[j - 1]);  // 提升最后一个可以提升的数, swap完之后, 后半段依旧是递减的
            reverse(nums.begin() + i, nums.end());  // 将低位变成所有低位的最小排列
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 5};
    sol.nextPermutation(nums);

    for (int num : nums)
        cout << num << endl;

    return 0;
}