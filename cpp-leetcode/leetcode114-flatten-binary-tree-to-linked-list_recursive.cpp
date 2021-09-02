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
    void flatten(TreeNode* root) {
        // 题意: 按照 root(1)->左子树撸直(2, 3) -> 右子树撸直(4,5,6) 连接
        if (root == nullptr) return;        
        if (root->left == nullptr) {  // 如果root没有left结点, 直接撸直右子树后return即可
            flatten(root->right);
            return;
        }
    
        TreeNode* pl = root->left;   // 递归调用撸直函数前保留现场 root 结点的 left/right 指针
        TreeNode* pr = root->right;
        flatten(root->left);
        flatten(root->right);

        root->right = pl;              // 先把左子树的所有left结点撸直的结果挂上去
        root->left = nullptr;
        while (pl-> right != nullptr)  // 先把左子树的所有right结点遍历出来后挂上去
            pl = pl->right;
        
        pl->right = pr;         // 最后将右子树撸直的结果挂接到左子树撸直结果的后面
    }
};

// Test
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);    
    root->left = new TreeNode(2); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(4); 
    root->right = new TreeNode(5); 
    root->right->left = nullptr; 
    root->right->right = new TreeNode(6); 

    sol.flatten(root);    

    return 0;
}