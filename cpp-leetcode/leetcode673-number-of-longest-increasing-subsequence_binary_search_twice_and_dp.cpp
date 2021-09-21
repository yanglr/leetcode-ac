#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        const int N = nums.size();

        vector<vector<pair<int, int>>> dp(N + 1);  /* dp table */
        int curMaxLen = 0;
        for (int i = 0; i < N; i++)
        {
            // bsearch insertion point
            int L = 0, R = curMaxLen;
            while (L < R)
            {
                int mid = L + (R - L) / 2;
                if (dp[mid].back().first < nums[i])
                    L = mid + 1;
                else R = mid;
            }
            // bsearch number of options
            int options = 1;
            int row = L - 1;
            if (row >= 0)
            {
                int L1 = 0, R1 = dp[row].size();
                while (L1 < R1)
                {
                    int mid = L1 + (R1 - L1) / 2;
                    if (dp[row][mid].first < nums[i])
                        R1 = mid;
                    else L1 = mid + 1;
                }
                options = dp[row].back().second;
                options -= (L1 == 0) ? 0 : dp[row][L1 - 1].second;
            }

            dp[L].push_back({nums[i], dp[L].empty() ? options : dp[L].back().second + options});
            if (L == curMaxLen) curMaxLen++;
        }        
        return dp[curMaxLen - 1].back().second;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    auto res = sol.findNumberOfLIS(nums);
    cout << res << endl;

    return 0;
}