#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
 public:
  bool checkSubarraySum(vector<int>& nums, int k) {
      // 同余定理: (sum2 - sum1) % k == 0 <=> sum2 % k = sum1 % k 
      // sum2: sum[0..i], sum1: sum[0..j], 前缀和之差对应的区间[i+1, j], 长度为j-i
      unordered_map<int, int> dict;  // map: 某个前缀和%k得到的余数->pos
      dict[0] = -1;  /* 特殊情况sum1 == N*k, 则前缀和之差的被减数(对应的余数为0)可有可无了, 长度按更长的算, 即i+1或i-(-1) */
      int preSum = 0;
      for (int i = 0; i < nums.size(); i++)
      {
          preSum += nums[i]; // preSum[0..i]
          if (k != 0)        // 本题中 1 <= k <= 2^31 - 1
              preSum %= k;
          if (dict.count(preSum))
          {
              int len = i - dict[preSum];  // i - j
              if (len >= 2)
                  return true;
          }
          else  /* 哈希表中还不存在该余数, 就把其index 加进来 */
              dict[preSum] = i;
      }

      return false;
  }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {3, 6, 9, 1};
    int k = 6;

    auto res = sol.checkSubarraySum(nums, k);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}