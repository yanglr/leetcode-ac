#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        vector<int> res(2);
        // 双指针, 先固定一个
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};

// 下面是测试
int main()
{
	Solution sol;
	vector<int> arr = {3, 2, 4};
	vector<int> res = sol.twoSum(arr, 7);
	for (int i : res)
		printf("%d ", i);
	return 0;
}