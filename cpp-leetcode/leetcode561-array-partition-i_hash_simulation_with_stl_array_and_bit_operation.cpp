#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const int max_val = *max_element(nums.begin(), nums.end());
        const int min_val = *min_element(nums.begin(), nums.end());
        const int offset = -min_val;
        vector<int> countDict(max_val - min_val + 1);

        for (int num : nums)
            ++countDict[num + offset];

        int res = 0;
        int index = 0;
        int n = min_val;

        while (n <= max_val)
        {
            if (countDict[n + offset] == 0)
            {
                ++n;
                continue;
            }
            res += (++index & 1) ? n : 0;
            --countDict[n + offset];
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {6, 2, 6, 5, 1, 2};
    int res = sol.arrayPairSum(nums);
    cout << res << endl;

    return 0;
}