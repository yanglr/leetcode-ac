#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;        
        const int len = nums.size();		
        int cand1, cand2;           /* 最多有2个众数(出现超过 ⌊n/3⌋ 次), 后面打擂台更新 */
        int votes1 = 0, votes2 = 0; 
        // 第1阶段 - 成对抵销
        for (int i = 0; i < len; i++)
        {
            // votes1 之前已经出现过, 这里再次出现
            if (votes1 > 0 && nums[i] == cand1) votes1++;
            else if (votes2 > 0 && nums[i] == cand2) votes2++;
            // cand1 第一次出现
            else if (votes1 == 0)
            {
                cand1 = nums[i];
                votes1 = 1;
            }
            else if (votes2 == 0)
            {
                cand2 = nums[i];
                votes2 = 1;
            }
            else /* cand1或cand2 之前已经出现过, 但此时第3个数(竞争者)第1次出现 */
            { 
                votes1--;
                votes2--;
            }
        }

        // 第2阶段 - 计数, 数目要超过三分之一
        votes1 = 0, votes2 = 0;
        for (auto &num : nums)
        {
            if (num == cand1) votes1++;
            else if (num == cand2) votes2++;
        }
        if (votes1 > len / 3)
            res.push_back(cand1);
        if (votes2 > len / 3)
            res.push_back(cand2);
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};
    auto res = sol.majorityElement(nums);
    for (auto &num : res)
        cout << num << endl;
    
    return 0;    
}