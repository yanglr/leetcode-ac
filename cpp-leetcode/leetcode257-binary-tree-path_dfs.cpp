#include<vector>
#include<algorithm>
#include<iostream>
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, "", res);
        return res;
    }
    void dfs(TreeNode *root, string path, vector<string>& res)
    {
        string curPath = path;
        if (!root) return;
        // 由于是从上到下的访问顺序, root的值必然需先放进去
        curPath.append(to_string(root->val)); /* curPath.push_back(root->val + '0'); 使用这种方式没法处理结点值是负数的情形 */
        if (root->left == nullptr && root->right == nullptr)
            res.push_back(curPath);
        else
        {
            curPath.append("->");
            dfs(root->left, curPath, res);
            dfs(root->right, curPath, res);
        }
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = nullptr;

    vector<string> res = sol.binaryTreePaths(root);

    return 0;
}