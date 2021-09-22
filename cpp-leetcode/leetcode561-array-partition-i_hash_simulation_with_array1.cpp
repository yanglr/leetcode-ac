#include<vector>
#include<array>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        const int maxVal = 10000;
        array<int, 2*maxVal + 1> countDict{};

        for (int num : nums)
            ++countDict[num + maxVal];

        int ans = 0;
        int n = -maxVal;
        bool first = true;

        while (n <= maxVal)
        {
            if (countDict[n + maxVal] == 0)
            {
                ++n;
                continue;
            }
            if (first)
            {
                ans += n;
                first = false;
            }
            else first = true;
            --countDict[n + maxVal];
        }
        return ans;
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