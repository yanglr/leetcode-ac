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
    TreeNode* dfs(vector<int>& nums, int startPos, int endPos)
    {
        if (startPos > endPos) return nullptr;
        if (startPos == endPos) return new TreeNode(nums[startPos]);
        int mid = startPos + (endPos - startPos)/2;
        auto root = new TreeNode(nums[mid]);
        root->left = dfs(nums, startPos, mid - 1);
        root->right = dfs(nums, mid+1, endPos);
        return root;
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