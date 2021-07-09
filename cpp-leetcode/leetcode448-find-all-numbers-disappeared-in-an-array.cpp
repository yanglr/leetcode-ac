#include<algorithm>
#include<vector>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
		unordered_set<int> se(nums.begin(), nums.end());
		int i = 0;
        int n = nums.size(); // 原始的size
		vector<int>res;
		for(i = 1; i <= n; ++i){
			if(se.find(i) == se.end())
				res.push_back(i);
		}
		return res;		
    }
};

int main()
{
	Solution sol;
    vector<int> nums = { 4,3,2,7,8,2,3,1 };
	auto res = sol.findDisappearedNumbers(nums);
	return 0;
}