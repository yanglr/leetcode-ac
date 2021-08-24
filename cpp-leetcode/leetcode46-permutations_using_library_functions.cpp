#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end()); /* 先排序，得到字典序最小的，以满足next_permutation容器的需要 */
        vector<vector<int>> res;
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end()))
        {
            res.push_back(nums);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = sol.permute(nums);
    
    return 0;
}