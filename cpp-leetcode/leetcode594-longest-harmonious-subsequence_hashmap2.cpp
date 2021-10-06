#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> dict;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            dict[nums[i]]++;
        
        int maxLen = 0;
        for (auto it = dict.begin(); it != dict.end(); ++it)
        {
            int k = it->first;
            if (dict.find(k + 1) != dict.end())
            {
                maxLen = max(maxLen, it->second + dict[k + 1]);
            }
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