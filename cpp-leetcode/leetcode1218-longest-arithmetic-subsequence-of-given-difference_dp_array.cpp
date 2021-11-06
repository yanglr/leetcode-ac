#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

const int K = 1e5;
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        const int N = arr.size();
        int count = 0;
        for (auto& num : arr)
        {
            if (num == arr.front()) count++;
        }
        if (diff == 0 && count == N) return N;
        
        int res = 1;
        int dp[2*K+1];
        memset(dp, 0, sizeof(dp));
        for (auto& num : arr)
        {
            dp[num + K] = 1;
            if (dp[num - diff + K] != 0)
                dp[num + K] = dp[num - diff + K] + 1;
        }        
        for (auto& num : dp)       
            res = max(res, num);
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> arr = {1, 5, 7, 8, 5, 3, 4, 2, 1};
    int diff = -2;
    auto res = sol.longestSubsequence(arr, diff);
    cout << res << endl;

    return 0;
}
