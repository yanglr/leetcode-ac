#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

/* index sort 解法 - wisdompeak */
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        nums.insert(nums.begin(), 0); /* 由于数组下标从0开始, 这里在最前方插入1个0, 就可以应用刚才的算法思想了 */
        int len = nums.size();

        for (int i = 0; i < len; i++)
        {
            while (nums[i] != i && nums[i] >= 0 && nums[i] < len && (nums[i] != nums[nums[i]]))
            {
                swap(nums[i], nums[nums[i]]);  // 保证不出现数组越界 nums[i] >= 0 && nums[i]<len
                /* nums[i] != nums[nums[i]]: 出现相等的数时, 如果swap会出现死循环, 于是跳过之 */
            }
        }
        for (int k = 1; k < len; k++)
        {
            if (nums[k] != k)
                return k;
        }

        return len;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {3,4,-1,1};
    int res = sol.firstMissingPositive(nums);
    cout << res << endl;
    
    return 0;
}