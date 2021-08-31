#include<unordered_map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> dict;
        dict.insert({0, -1});

        const int len = nums.size();
        int count = 0;
        int maxLen = 0;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] == 0) count++;
            else count--;
            if (dict.find(count) != dict.end())
            {
                int j = i - dict[count];
                maxLen = max(maxLen, j);
            }
            else dict[count] = i;
        }

        return maxLen;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 0};
    auto res = sol.findMaxLength(nums);
    cout << res << endl;

    return 0;
}