#include<cstdio>
#include<iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* p;
        p=root->left;
        root->left=root->right;
        root->right=p;
        
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};

// 以下为验证 
int main() {
    TreeNode *root = new TreeNode(-1);
    TreeNode *temp;
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(0);

    Solution sol;

    cout << root->left->val << endl;
    temp=sol.invertTree(root);
    cout << temp->left->val << endl;
    cout << temp->left->left->val << endl;
	    
    return 0;
}