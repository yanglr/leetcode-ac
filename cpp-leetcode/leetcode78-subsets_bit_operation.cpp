#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> res;    
    for (int s = 0; s < (1 << n); ++s) {  // s表示一个状态state
      vector<int> curSet;
      for (int i = 0; i < n; ++i)
        if ((s & (1 << i)) > 0)  /* 从末位开始, 循环判断当前位是不是1. 注意位运算的优先级不比+、>、<、=高, 可以加括号后判断>0, 也可以简写为 if (s & (1 << i)) */
            curSet.push_back(nums[i]);
      res.push_back(curSet);
    }
    return res;
  }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 1,2,3 };
    auto res = sol.subsets(nums);

    return 0;
}