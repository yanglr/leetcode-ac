#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);  
    }
    TreeNode* dfs(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            TreeNode* root = new TreeNode(nums[start]);
            return root;
        }
        if (start < end)
        {
            int m = (end - start) / 2 + start;
            auto leftChild =  dfs(nums, start, m - 1);
            auto rightChild =  dfs(nums, m + 1, end);
            TreeNode* root = new TreeNode(nums[m], leftChild, rightChild);
            return root;
        }
        return nullptr;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    TreeNode* res = sol.sortedArrayToBST(nums);
    cout << res->val << endl;

    return 0;
}