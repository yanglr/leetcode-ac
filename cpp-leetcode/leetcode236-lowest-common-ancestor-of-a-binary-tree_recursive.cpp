#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
/* Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);   /* 在左子树中是否能找到P或Q结点, 返回dfs结束时的TreeNode */
        TreeNode* right = lowestCommonAncestor(root->right, p, q); /* 在右子树中是否能找到P或Q结点, 返回dfs结束时的TreeNode */
        if (left != nullptr && right != nullptr)
            return root;

        TreeNode* res = left == nullptr ? right : left;
        return res;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(3);
    TreeNode *n1 = new TreeNode(5);
    TreeNode *n2 = new TreeNode(1);
    TreeNode *n3 = new TreeNode(6);
    TreeNode *n4 = new TreeNode(2);
    TreeNode *n5 = new TreeNode(0);
    TreeNode *n6 = new TreeNode(8);
    TreeNode *n7 = new TreeNode(7);
    TreeNode *n8 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n4->left = n7;
    n4->right = n8;
    TreeNode *res = sol.lowestCommonAncestor(root, n3, n8);
    
    return 0;
}