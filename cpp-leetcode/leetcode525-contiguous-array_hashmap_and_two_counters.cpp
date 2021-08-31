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

        int zero = 0; // 数组中从0开始到i, 0出现的次数
        int one = 0;  // 数组中从0开始到i, 1出现的次数
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0) zero++;
            else one++;

            int gap = zero - one; /* 一开始0与1的数量之差记作gap = zero - one, 假如后面0与1的数量之差又出现gap, 说明两者在新走过的这段距离中势均力敌(数量相等), 找到上一次出现的位置j, 两者相减即可. */
            if (dict.count(gap))
            {
                int j = i - dict[gap];
                maxLen = max(maxLen, j);
            }
            else dict[gap] = i;
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