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
    int findTilt(TreeNode* root) {
        int tiltSum = 0;
        dfs(root, tiltSum);
        return tiltSum;
    }
    // dfs: 计算当前结点的所有孩子节点之和
    int dfs(TreeNode* root, int& tiltSum)
    {
        if (root == nullptr) return 0;
        int leftValSum = dfs(root->left, tiltSum);
        int rightValSum = dfs(root->right, tiltSum);
        int curNodeTilt = abs(leftValSum - rightValSum); /*  计算当前结点的坡度 */
        tiltSum += curNodeTilt;
        
        return leftValSum + rightValSum + root->val;
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

    auto res = sol.findTilt(root);   
    cout << res << endl;

    return 0;
}