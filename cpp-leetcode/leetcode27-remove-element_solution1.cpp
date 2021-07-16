#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0)
            return 0;
            
        // 双指针法
        int p = 0; /* p是从头开始走的指针，也有计数器的作用。只有遇到不等于目标值val的时候才移动1步, 且nums[p]总是更新为≠val的值 */
        for(int i = 0; i < nums.size(); i++)  /* 一开始p和循环指针i都指向0，后面不同步移动 */
        {
            if(nums[i] != val)
            {
                nums[p] = nums[i];
                p++;
            }
        }
        return p;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int target = 2;
    int res = sol.removeElement(nums, target);
    cout << res << endl;

    return 0;
}