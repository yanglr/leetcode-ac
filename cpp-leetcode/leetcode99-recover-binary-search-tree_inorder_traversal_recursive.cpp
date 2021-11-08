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
    TreeNode* lastSeen = new TreeNode(INT_MIN);
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
public:
    void recoverTree(TreeNode* root) 
    {
       inOrder(root);       
       int tempVal = first->val;
       first->val = second->val;
       second->val = tempVal;
    }
    
    void inOrder(TreeNode* node)
    {
        if (node == nullptr) return;
        
        inOrder(node->left);        
        if (node->val >= lastSeen->val)
            lastSeen = node;
        else /* 出现异常点 */
        {
            if (first == nullptr)  /* 第1处异常点 */
            {
                first = lastSeen;
                second = node;
                lastSeen = node;
            }
            else /* 第2处异常点 */
            {
                second = node;
                return;
            }
        }        
        inOrder(node->right);            
    }    
};

// Test
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(3);    
    root->left = new TreeNode(1); 
    root->right = new TreeNode(4); 
    root->right->left = new TreeNode(2); 
    
    sol.recoverTree(root);
    cout << root->val << endl;    /* 输出恢复后的根结点的值 */

    return 0;
}