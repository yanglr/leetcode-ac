#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
/** Definition for a binary tree node. */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pVal(p->val), qVal(q->val);
        
        while (root) {
            int rootVal = root->val;
            if ((rootVal > pVal && rootVal > qVal)) root = root->left;
            else if (rootVal < pVal && rootVal < qVal) root = root->right;
            else return root;
        }
        return root;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(6);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(8);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(9);
    TreeNode *n7 = new TreeNode(3);
    TreeNode *n8 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n4->left = n7;
    n4->right = n8;
    TreeNode *res = sol.lowestCommonAncestor(root, n1, n7); /* 输出2与3的LCA */
    cout <<  res->val << endl;
    
    return 0;
}