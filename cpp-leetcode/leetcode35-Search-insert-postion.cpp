#include<cstdio>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        int len = nums.size();
        int startIndex = -1;        
        if (it != nums.end())
        {
            startIndex = it - nums.begin();
            return startIndex;           
        }
        else
        {
            if (target < nums[0])
            {
                return 0;
            }
            if (target > nums[len-1])
            {
                return len;
            }

            for (int i = 1; i < len; i++)
            {
                if (target > nums[i-1] && target < nums[i])
                {
                    startIndex = i;
                }
            }
        }        
        return startIndex;
    }
};

// Below is testing
int main()
{
    Solution sol;
    vector<int> nums = {1,3,5,6};
    auto target = 5;
    printf("%d", sol.searchInsert(nums, target));

    return 0;
}
