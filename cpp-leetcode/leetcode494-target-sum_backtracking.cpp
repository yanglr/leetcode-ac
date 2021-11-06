#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int count = 0;    
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int N = nums.size();
        if (N == 0 && target != 0) return 0;
        int index = 0;
        dfs(nums, N, index, 0, target);
        return count;        
    }
    /* index: 计算算到了index(index处于区间[0, N])处, index = 0表示第1个数还没加进来时 */
    void dfs(vector<int>& nums, int N, int index, int curSum, int sum) {
        if (index == N) return;
        int cur = nums[index];
        // Choose
        int theAdd = curSum + cur;
        if (index == N - 1 && theAdd == sum) count++;
        int theMinus = curSum - cur;        
        if (index == N - 1 && theMinus == sum) count++;
        // Explore        
        dfs(nums, N, index + 1, theAdd, sum);
        dfs(nums, N, index + 1, theMinus, sum);
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    auto res = sol.findTargetSumWays(nums, target);
    cout << res << endl;

    return 0;
}