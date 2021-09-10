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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        postOrder(root, res);
        return res;
    }
    void postOrder(TreeNode* root, vector<int>& res)
    {
        if (!root) return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = sol.postorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}