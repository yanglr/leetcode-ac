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
    int minDiffInBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        int minGap = INT_MAX;
        for (int i = 0; i < vals.size() - 1; i++)
        {
            if (abs(vals[i + 1] - vals[i]) < minGap)
                minGap = abs(vals[i + 1] - vals[i]);
        }
        return minGap;
    }

    void inorder(TreeNode* root, vector<int>& vals)
    {
        if (root == nullptr) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = NULL;
    auto res = sol.minDiffInBST(root);
    cout << res << endl;

    return 0;
}