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
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int lDepth = getMaxDepth(root->left);
        int rDepth = getMaxDepth(root->right);
        int disThroughRoot = lDepth + rDepth;
        int leftMaxDis = diameterOfBinaryTree(root->left);
        int rightMaxDis = diameterOfBinaryTree(root->right);
        return max(disThroughRoot, max(leftMaxDis, rightMaxDis));
    }
    int getMaxDepth(TreeNode* root)  
    {
        if (root == nullptr) return 0;
        
        int lDepth = getMaxDepth(root->left);
        int rDepth = getMaxDepth(root->right);
        return max(lDepth, rDepth) + 1;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(4);
    TreeNode *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n3->left = NULL;
    n3->right = NULL;
    n4->left = NULL;
    n4->right = NULL;   
     
    auto res = sol.diameterOfBinaryTree(root);
    cout << res << endl;
    
    return 0;
}