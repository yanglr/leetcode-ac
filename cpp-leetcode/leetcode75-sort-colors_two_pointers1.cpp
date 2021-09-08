#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /* 用两个指针 zero, two作为分隔板. zero: 使得所有在zero左边的元素都为0; two, 使得所有在two右边的元素都为2. 
        * 另外始终让让遍历的指针i指向两个分隔板之间的部分, 即始终保持i <= two 和 i >= zero
        */
        const int len = nums.size();
        int zero = 0, two = len - 1;
        int i = 0;
        while (i <= two)  /* 始终保持i <= two */
        {
            if (nums[i] == 0) 
            {
                swap(nums[i], nums[zero]);
                zero++;
            }
            else if (nums[i] == 2) 
            {
                swap(nums[i], nums[two]);
                two--;
            }
            else i++;
            i = max(zero, i);  /* 始终保持 i >= zero */
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