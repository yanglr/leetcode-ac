#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* 题目要求: 时间复杂度为 O(n) */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dict;
        for (int num : nums) {
            if (dict.count(num)) continue;  // 重复出现的数不用再考虑一次
            
            auto preIt = dict.find(num - 1);
            auto nextIt = dict.find(num + 1);
            
            int preCount = preIt != dict.end() ? preIt->second : 0;
            int nextCount = nextIt != dict.end() ? nextIt->second : 0;

            if (preCount > 0 && nextCount > 0)
                dict[num] = dict[num - preCount] = dict[num + nextCount] = preCount + nextCount + 1;
            else if (preCount > 0)
                dict[num] = dict[num - preCount] = preCount + 1;
            else if (nextCount > 0)
                dict[num] = dict[num + nextCount] = nextCount + 1;
            else dict[num] = 1;
        }

        int maxLen = 0;
        for (const auto &kvp : dict)
            maxLen = max(maxLen, kvp.second);
            
        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 100,4,200,1,3,2,4 };
    auto res = sol.longestConsecutive(nums);
    cout << res << endl;

    nums = { 0,3,7,2,5,8,4,6,0,1 };
    res = sol.longestConsecutive(nums);
    cout << res << endl;

    return 0;
}