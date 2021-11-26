#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int N = nums.size();
        int i = 0; // i: 滑动窗口左边界, 固定右边界, 移动左边界
        int count = 0; // 已经使用了多少次反转次数
        int res = 0; // res: max len
        for (int j = 0; j < N; j++)
        {
            if (nums[j] == 1) // 新加入窗口右侧的数是1, 不需要使用反转次数
                res = max(res, j - i + 1);
            else {
                count++;
                while (count > k) // 此时使用的反转次数超了, 需要移动左边界, 直到窗口使用的反转次数减小回到k为止
                {
                    if (nums[i] == 0)                    
                        count--;
                    i++;
                }
                res = max(res, j - i + 1);
            }
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