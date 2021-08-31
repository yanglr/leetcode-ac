#include<vector>
#include<queue>
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
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return {};
        vector<int> res;

        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty())
        {
            vector<int> curLevel;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode *p = q.front();
                q.pop();
                curLevel.push_back(p->val);

                if (p->left != nullptr) q.push(p->left);
                if (p->right != nullptr) q.push(p->right);
            }
            res.push_back(curLevel.back());
        }
        return res;        
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);
    TreeNode *n3 = new TreeNode(5);
    TreeNode *n4 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->right = n3;    
    n2->right = n4;
    n3->left == NULL;
    n3->right == NULL;
    n4->left == NULL;
    n4->right == NULL;

    auto res = sol.rightSideView(root);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}