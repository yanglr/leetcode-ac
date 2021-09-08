#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        const int len = nums.size();
        int zero = 0, two = len - 1;
        for (int i = 0; i <= two; i++)
        {
            if (nums[i] == 2)
            {
                swap(nums[i], nums[two]);
                two--;
                i--; /* i扫描完后就i++了, 这里i--是为了处理从two位置新swap到i位置的值(可能是0、1、2) */
            }
            else if (nums[i] == 0)
            {
                swap(nums[i], nums[zero]);
                zero++; /* 这里不需要i--是因为左边都是处理完了的 */
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2,0,2,1,1,0};
    sol.sortColors(nums);
    for (auto &num : nums)
        cout << num << endl;
    
    return 0;
}