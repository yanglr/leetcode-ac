#include<vector>
#include<deque>
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
        vector<int> res;
        deque<TreeNode*> st;  /* 辅助栈, 处理顺序是: 
        访问root -> 遍历左子树 -> 输出左子树 -> 输出root -> 遍历右子树 -> 输出右子树 */
        TreeNode* p = root;

        while (!st.empty() || p != NULL)
        {
            /* 遍历part 1: 把根结点、左子树的结点依次压入栈中, 这样如果在访问右子树之前出栈, 根结点必然最后一个出来 */
            while (p != NULL)
            {
                st.push_front(p);
                p = p -> left;
            }

            p = st.front();
            st.pop_front();
            res.push_back(p -> val);  /* 按序向 res数组中插入栈的top位置的每个值 */
            
            /* 遍历part 2: 把剩下的右子树的结点依次压入栈中 */
            p = p -> right;
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
	
	vector<int> res = sol.inorderTraversal(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}