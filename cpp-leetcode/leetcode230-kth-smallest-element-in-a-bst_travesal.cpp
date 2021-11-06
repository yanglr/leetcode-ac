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
    int kthSmallest(TreeNode* root, int k) {
        if (root == NULL) return 0;
        int res;
        vector<int> vals;
        inorder(root, vals);
        if (vals.size() < k) res = 0;
        else res = vals[k-1];
        
        return res;
    }
    void inorder(TreeNode* root, vector<int>& vals)
    {
        if (root == NULL) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);    
    
    auto res = sol.kthSmallest(root, 3);
    cout << res << endl;

    return 0;
}