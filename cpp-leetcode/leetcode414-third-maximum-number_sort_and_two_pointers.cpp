#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int p = 0; // 用指针p 指向发现的新值的index
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[p] != nums[i])
            {
                p++;
                nums[p] = nums[i];
            } 
        }
        int len = p + 1; // 现在不含重复的数的子区间为 [0, p]
        if (p + 1 < 3) return nums[p];
        return nums[p - 2];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 4, 10};
    auto res = sol.thirdMax(arr);
    cout << res << endl;

    return 0;
}