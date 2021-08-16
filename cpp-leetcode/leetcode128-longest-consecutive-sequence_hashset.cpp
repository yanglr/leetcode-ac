#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/* 题目要求: 时间复杂度为 O(n) */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> st;
        for (auto &num : nums)
            st.insert(num);
        
        int maxLen = 0;
        for (int num : nums)            
        {
            if (!st.count(num - 1)) {
                int curLen = 0;                
                while (st.count(num))
                {
                    curLen++;
                    num++;
                }
                maxLen = max(maxLen, curLen);
            }            
        }
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