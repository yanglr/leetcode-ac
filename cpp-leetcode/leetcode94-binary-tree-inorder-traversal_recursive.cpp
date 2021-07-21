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

/* 中序遍历顺序: 左根右 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};

        TreeNode* p = root;
        vector<int> res = inorderTraversal(root->left);  // left
        res.push_back(root->val);
        vector<int> right = inorderTraversal(root->right);
        res.insert(res.end(), right.begin(), right.end());

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
	
	vector<int> res = sol.inorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}