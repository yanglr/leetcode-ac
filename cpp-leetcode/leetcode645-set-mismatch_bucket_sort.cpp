#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++)
		{
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) /* 不断地swap, 把index是i的数放到合适的位置上, nums[nums[i] - 1] != nums[i] 表示遇到相等的数不需要swap, 否则会死循环 */
			{
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        int repeatNum = -1, missingNum = -1;
        for (int i = 0; i < n; i++)
		{
            if (nums[i] != i + 1)
			{
                repeatNum = nums[i];
                missingNum = (i == 0) ? 1 : nums[i - 1] + 1;
            }
        }
        return {repeatNum, missingNum};
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    auto res = sol.findErrorNums(nums);
    for (auto &num : res)
        cout << num << endl;
    
    return 0;
}