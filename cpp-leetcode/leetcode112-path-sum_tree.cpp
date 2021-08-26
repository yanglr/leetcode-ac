#include <algorithm>
#include <iostream>
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1.明显的出口, 考虑第1层为NULL的情形 
        if (root == NULL) return false;

        /* 2.具体逻辑的出口: 考虑第1层的左右孩子为NULL的情形 */ 
        if (root->left == NULL && root->right == NULL)
            return root->val == targetSum;  /* 注意这里不是直接return一个bool值, 而是return一个含变量的表达式(递归地判断叶子节点) */
        
        // 3.自顶向下进行递归调用
        bool hasLeftPath = hasPathSum(root->left, targetSum - root->val);
        bool hasRightPath = hasPathSum(root->right, targetSum - root->val);
        return hasLeftPath || hasRightPath;
    }
};

// Test
int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(1);    
    root->right = new TreeNode(3); 
    root->left = new TreeNode(2); 
    root->right->left = nullptr;
    root->right->right = nullptr;
    root->left->left = nullptr;
    root->left->right = nullptr;
	int targetSum = 4;
	bool res = sol.hasPathSum(root, targetSum);
    cout << (res == true ? "true" : "false") << endl;    

	targetSum = 5;
	res = sol.hasPathSum(root, targetSum);
    cout << (res == true ? "true" : "false") << endl; 

    return 0;
}