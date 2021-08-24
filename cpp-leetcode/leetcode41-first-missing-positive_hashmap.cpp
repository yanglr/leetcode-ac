#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        unordered_map<int, int> dict;
        long max = 0; // max: 最长连续区间的结束位置的值
        for (int k = 0; k < nums.size(); k++)
        {
            if (nums[k] > 0)
                dict[nums[k]] = 1;  /* 题意: 找没有出现的最小的正整数, 于是0和负数不用考虑 */
            if (nums[k] > max)
                max = nums[k];
        }
        long res = max + 1;
        for (long k = 1; k <= max; k++)
        {
            if (dict.count(k) == 0)
            {
                res = k;
                break;
            }
        }
        return res;
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