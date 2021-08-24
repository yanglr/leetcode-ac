#include <algorithm>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return {{}};
        if (nums.size() == 1) return {nums};
        vector<vector<int>> result;
        dfs(nums, result, 0);      /* dfs (backTracking): 开始回溯, 一开始要处理的区间是[0, len-1] */
        return result;
    }

private:
    /* 每次去处理子区间 [startPos, len - 1], startPos表示将要处理的剩下数中第一个数的index */
    void dfs(vector<int> nums, vector<vector<int>>& result, int startPos) {   
        if (startPos == nums.size() - 1) {  /* 已经排列到len 位置，超出了数组范围，这意味着此时已经完成了排列 */
            result.push_back(nums); 
            return;
        }

        unordered_set<int> usedDict;  /* 记录哪些数已经用过 */
        for (int i = startPos; i < nums.size(); ++i) { /* startPos 是当前正在选择的位, i 是startPos位置将要选择的数的当前位置 */
            swap(nums[i], nums[startPos]);   /* Choose: 将第i位数字交换到startPos位置, 完成startPos位置的选择 */
            // 仅当"当前数"没被使用过时才可以递归调用
            if (!usedDict.count(nums[startPos])) {
                usedDict.insert(nums[startPos]);
                dfs(nums, result, startPos + 1);  /* Explore using dfs: 递归的向前推进1步(1个格子), 选择下一位数字  */
            }
            swap(nums[i], nums[startPos]);   /* Un-choose: 重置为选择之前的状态，重新选择下一位数字  */
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2, 3};
    vector<vector<int>> res = sol.permuteUnique(nums);
    
    return 0;
}