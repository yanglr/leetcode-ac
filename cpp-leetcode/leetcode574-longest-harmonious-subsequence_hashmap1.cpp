#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> dict; // map: num -> count
        for (const auto& num : nums)
            dict[num]++;
        
        int maxLen = 0;
        for (const auto& kvp : dict)
        {
            int k = kvp.first;
            if (dict.count(k + 1)) /* 往高处找(key -> key + 1), 进行贪心 */
                maxLen = max(maxLen, dict[k] + dict[k + 1]);
            if (dict.count(k - 1)) /* 往低处找(key -> key - 1), 进行贪心 */
                maxLen = max(maxLen, dict[k] + dict[k - 1]);            
        }
        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.findLHS(nums);
    cout << res << endl;

    return 0;
}