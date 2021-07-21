#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree node.
*/
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 后序遍历顺序: 左右根 */
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        vector<int> res;
        deque<TreeNode*> st; /* 基于deque的辅助栈, 输出(遍历)顺序: 左 右 根 */
        TreeNode* p = root;
        while (p != NULL || !st.empty())
        {
            while (p != NULL)
            {
                st.push_front(p->left);
                res.push_back(p->val);
                p = p->right;
            }
            p = st.front();
            st.pop_front();
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = NULL;
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = sol.postorderTraversal(root);
    for (auto num : res)
        cout << num << endl;

    return 0;
}