#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        if (root->left == nullptr && root->right == nullptr) return {{root->val}};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> curLevel;
            for (int i = q.size() ; i > 0; --i)
            {
                TreeNode* p = q.front();
                q.pop();
                curLevel.push_back(p->val);                
                if (p->left != nullptr) q.push(p->left);    /* 不能写出 !p->left 或 !(p->left) */
                if (p->right != nullptr) q.push(p->right);                
            }
            res.push_back(curLevel);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// Test
int main()
{
	Solution sol;

	TreeNode* root = new TreeNode(3);    
    root->left = new TreeNode(9); 
    root->right = new TreeNode(20); 
    root->right->left = new TreeNode(15);     
    root->right->right = new TreeNode(7);     
    root->right->left->left = nullptr;     
    root->right->left->right = nullptr;     
    root->right->right->left = nullptr;     
    root->right->right->right = nullptr;          

    vector<vector<int>> res = sol.levelOrderBottom(root);
    
    return 0;
}