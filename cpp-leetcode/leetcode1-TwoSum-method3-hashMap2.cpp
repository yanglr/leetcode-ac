#include<iostream>
#include<unordered_map>
#include<vector>
// #include<algorithm>
using namespace std;
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> dict;
		vector<int> res(2,-1), emptyVect;
		for(int i=0;i<nums.size();i++)
		{
			int query=target-nums[i];		
			if(dict.find(query)==dict.end()) dict[nums[i]]=i;     // 逆序的map映射: value->index
			else {
				res[1]=i;
				res[0]=dict[query];
				return res;	
			}
		}
		return emptyVect;
	}
};
// 下面是测试
int main()
{
    Solution sol;
    vector<int> arr={3,2,4};
    vector<int> res = sol.twoSum(arr, 8);
    for(int i:res)
		printf("%d ",i);
    return 0;
}