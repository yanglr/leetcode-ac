#include<deque>
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
        vector<int> res;
        deque<TreeNode*> st;  /* 基于deque的辅助栈, 输出(遍历)顺序: 根 左 右, 于是放入顺序遍历顺序: 右 左 根 */
        // 遍历 part1 - 根结点
        if (root != NULL)
            st.push_front(root);        
        
        while (!st.empty())
        {
            TreeNode* p = st.front();
            res.push_back(p->val);       // 只要栈里有node，就输出栈顶元素到res数组
            st.pop_front();

            // 遍历 part2 - 右子树
            if (p -> right != NULL)
                st.push_front(p -> right);
            // 遍历 part3 - 左子树
            if (p -> left != NULL)
                st.push_front(p -> left);                        
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

    vector<int> res = sol.preorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}