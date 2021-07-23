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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        if (root->left == NULL && root->right == NULL)
            return {{root->val}};
            
        queue<TreeNode*> q;
        q.push({root});    /* queue与deque相比少了一种初始化方式 */
        vector<vector<int>> res;

        while (!q.empty())
        {
            vector<int> curLevel;
            for (int i = q.size(); i > 0; i--)
            {
                TreeNode* p = q.front();    // 取出队头的node, 后面就可以删掉它了.
                q.pop();              /* 队列: 队尾进，队头出 */
                curLevel.push_back(p->val);
                if (p->left != NULL)
                    q.push(p->left);

                if (p->right != NULL)
                    q.push(p->right);                                              
            }            
            res.push_back(curLevel);
        }
        
        return res;
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
	
	vector<vector<int>> res = sol.levelOrder(root);

    return 0;
}