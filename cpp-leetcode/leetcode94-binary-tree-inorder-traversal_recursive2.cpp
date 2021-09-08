#include<vector>
#include<deque>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL) return {};
        vector<int> vals;
        inorderHelper(root, vals);
        return vals;
    }
    void inorderHelper(TreeNode* root, vector<int>& vals)  /* 这里的引用传递&不能忘了 */
    {
        if (root == NULL) return;
        inorderHelper(root->left, vals);
        vals.push_back(root->val);
        inorderHelper(root->right, vals);
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(1);    
    root->left = NULL; 
    root->right = new TreeNode(2); 
    root->right->left = new TreeNode(3); 
    
    vector<int> res = sol.inorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}