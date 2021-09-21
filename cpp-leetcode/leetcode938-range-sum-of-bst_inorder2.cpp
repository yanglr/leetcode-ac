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
    int L;
    int H;
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        L = low;
        H = high;
        inorder(root, sum);        
        return sum;
    }
    void inorder(TreeNode* root, int& sum)
    {
        if (!root) return;
        inorder(root->left, sum);
        int num = root->val;
        if (num >= L && num <= H)
            sum += num;
        inorder(root->right, sum);
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);    
    
    auto res = sol.rangeSumBST(root, 7, 15);
    cout << res << endl;

    return 0;
}