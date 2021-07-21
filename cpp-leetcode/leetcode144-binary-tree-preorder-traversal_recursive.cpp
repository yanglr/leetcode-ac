#include<stack>
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

/* 前序遍历顺序: 根 左 右 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<int> res;
        res.push_back(root->val);
        vector<int> left = preorderTraversal(root->left);
        vector<int> right = preorderTraversal(root->right);
        // 合并各个数组到res数组
        res.insert(res.end(),left.begin(),left.end());
        res.insert(res.end(),right.begin(),right.end());

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
	
	vector<int> res = sol.preorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}