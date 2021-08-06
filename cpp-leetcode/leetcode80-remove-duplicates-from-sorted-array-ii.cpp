#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 1, p = 0; // 用指针p 指向发现的新值的index
        int count = 1;
        int n = nums.size();
        while (i < n) {
            if (nums[p] == nums[i] && count == 0) i++;
            else {
                if (nums[p] == nums[i]) count--;
                else count = 1;
                p++;
                nums[p] = nums[i];
                i++;
            }
        }
        return nums.empty() ? 0 : p + 1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 0,0,1,1,1,2,2,2,2,3,3,3,6,6 };
    auto res = sol.removeDuplicates(nums);    
    cout << res << endl; 

    return 0;
}