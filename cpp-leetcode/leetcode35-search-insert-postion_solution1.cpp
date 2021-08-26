#include<cstdio>
#include<vector>
#include <algorithm>
using namespace std;

/* 基于find库函数来做, 分两种情况处理 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {        
        int len = nums.size();
        int pos = -1;
        auto it = find(nums.begin(), nums.end(), target);
        if (it != nums.end())
        {
            pos = it - nums.begin();
            return pos;           
        }
        else
        {
            if (target < nums[0]) return 0;
            if (target > nums[len-1]) return len;
            for (int i = 1; i < len; i++)
            {
                if (target > nums[i-1] && target < nums[i]) /* 题意: 数组中不会出现元素相等的情况 */
                    pos = i; /* 此时pos是insertPos, 即需要插入的位置 */
            }
        }        
        return pos;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    auto target = 5;
    printf("%d", sol.searchInsert(nums, target));

    return 0;
}