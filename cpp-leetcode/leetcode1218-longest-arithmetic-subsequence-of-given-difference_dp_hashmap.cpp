#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

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
        
        int res = 1;  // 记录最大长度
        unordered_map<int, int> dp; /* map: value -> length, dp[i]: 以nums[i]结尾的最长等差子序列的长度, 类似于LIS的dp数组定义 */
        for (auto& num : arr)
        {
            dp[num] = 1; /* 不能构成等差序列的情形, 最长的等差子序列的长度为1, 默认值可设置为 1 */
            if (dp.count(num - diff)) /* 如果num - diff 出现过, (num-diff)与num组成等差序列, 最大等差子序列的长度+1, 扩展出1个新的等差数列 */
                dp[num] = dp[num - diff] + 1;
        }        
        for (auto& kvp : dp)       
            res = max(res, kvp.second);

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
