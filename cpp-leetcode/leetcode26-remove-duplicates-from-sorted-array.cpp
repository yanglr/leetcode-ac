#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;  // Corner case
        int p = 0; // Use p always point to the position of last new value found
        for(int i=0; i<nums.size(); i++)
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