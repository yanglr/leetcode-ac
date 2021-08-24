#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int minSteps = 0;
        int endPos = 0; // 刚开始, 区间为[0, 0]

        int maxPos = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);  /* 此时, 区间更新为 [i, maxPos] */
            if (i == endPos)
            {
                endPos = maxPos;
                minSteps++;
            }        
        }        

        return minSteps;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int>nums = {2,3,0,1,4};
    auto res = sol.jump(nums);
    cout << res << endl;
    
    return 0;
}