#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();        
        int left = 0; // left: 滑动窗口左边界, 固定右边界, 移动左边界
        int j = 0; // j: 滑动窗口右边界right
        int preSum = 0; // 使用的反转次数 0 -> 1
        int res = 0;
        for (int j = 0; j < N; j++)
        {
            preSum += (nums[j] == 0 ? 1 : 0);
            if (preSum > k) // 一开始, 让反转次数达到k+1, 然后开始根据情况收缩左边界
            {
                while (left < j && nums[left] == 1) /* 在左边界每遇到一个1, 就直接移动左边界, 如果遇到1个0, 翻转次数又新腾出了1, 需要先更新preSum的值 */
                    left++;
                
                preSum -= 1;
                left++;
            }
            res = max(res, j - left + 1); // 此时, 反转次数恰好恢复到k, 可以更新结果了
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;
    auto res = sol.longestOnes(nums, k);
    cout << res << endl;

    return 0;
}