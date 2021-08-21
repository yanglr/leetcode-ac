#include<cstdio>
#include<vector>
using namespace std;
/* 本题要求原地in-place 操作 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int p = 0; // 用指针p 指向发现的新值的index
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[p] != nums[i])
            {
                p++;
                nums[p] = nums[i];
            }
        }
        return p+1;
    }
};

// 下面是测试
int main()
{
    Solution sol;
    vector<int> arr={3,2,4,8,3};
    auto res = sol.removeDuplicates(arr);
    printf("%d ",res);
    return 0;
}