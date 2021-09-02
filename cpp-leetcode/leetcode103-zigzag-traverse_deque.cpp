#include <iostream>
#include <vector>
#include <deque>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        if (root->left == nullptr && root->right == nullptr) return {{root->val}};

        vector<vector<int>> res;
        deque<TreeNode*> q {root};
        while (!q.empty())
        {
            vector<int> curLevel;
            for (int i = q.size() ; i > 0; --i)
            {
                TreeNode* p = q.front();
                q.pop_front();                
                curLevel.push_back(p->val);                
                if (p->left != nullptr) q.push_back(p->left); 
                if (p->right != nullptr) q.push_back(p->right);
            }
            res.push_back(curLevel);
        }
        
        for (int i = 0; i < res.size(); i++)
        {
            vector<int> curLevel = res[i];
            if (i % 2 == 1)
            {
                reverse(curLevel.begin(), curLevel.end());
                res[i] = curLevel;
            }
        }

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
    root->right->left->left = nullptr;     
    root->right->left->right = nullptr;     
    root->right->right = new TreeNode(7);
    root->right->right->left = nullptr;     
    root->right->right->right = nullptr;          

    vector<vector<int>> res = sol.zigzagLevelOrder(root);
    
    return 0;
}