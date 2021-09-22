#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree root->
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> curPath;
        dfs(root, targetSum, paths, curPath);
        return paths;
    }
    void dfs(TreeNode* root, int sum, vector<vector<int>>& paths, vector<int> curPath)
    {
        if (root == nullptr) return;
        curPath.push_back(root->val);  
        if (root->val == sum && root->left == nullptr && root->right == nullptr)
            paths.push_back(curPath);
        else
        {
            dfs(root->left, sum - root->val, paths, curPath);
            dfs(root->right, sum - root->val, paths, curPath);
        }
        curPath.pop_back();
    }
};
