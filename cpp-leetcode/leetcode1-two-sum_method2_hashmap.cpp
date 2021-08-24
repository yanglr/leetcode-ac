#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target)
		{
			unordered_map<int, int> dict;
			vector<int> result;
			for(int i = 0; i < nums.size(); i++) {
				dict[nums[i]] = i; // 顺序的map映射: value->index 
			}
			for(int i = 0; i < nums.size(); i++)
			{
				int query = target - nums[i];
				if(dict.find(query) != dict.end() && dict[query] > i)  // dict[query] > i是为了防止重复计算 
				{
					result.push_back(i);
					result.push_back(dict[query]);
					break;
				}
			}
			return result;
		}
};
// 下面是测试
int main()
{
    Solution sol;
    vector<int> arr1={3,2,2,2,2,2,4};
    vector<int> arr2={3,2,4};    
    vector<int> res1= sol.twoSum(arr1, 6); 
    vector<int> res2= sol.twoSum(arr2, 6);
	for (int i : res1)
		printf("%d ", i);
	printf("\n");
	for (int i : res2)
		printf("%d ", i);
	return 0;
}