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

struct Pack {
    int op; /* 0, to visit (表示还需要后续处理); 1, visited/print/save (不需要后续处理了, 就想取里面的值)  */
    TreeNode* node;
    Pack(int op, TreeNode* node) {
        this->op = op;
        this->node = node;
    }
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        deque<Pack*> st;
        st.push_front(new Pack(0, root));
        
        while (!st.empty())
        {
            Pack* cur = st.front(); // 先front(), 再pop
            st.pop_front();
            if (cur->node == nullptr)
                continue;  /* 此时该 TreeNode的val/left/right都没法取到, 故不需要处理  */
            if (cur->op == 1)
                res.push_back(cur->node->val);
            else
            {   
                /* 基于deque的辅助栈, 要求每一个结点及其子树的输出(遍历)顺序: 根 左 右, 于是放入顺序遍历顺序: 右 左 根 */
                st.push_front(new Pack(0, cur->node->right));
                st.push_front(new Pack(0, cur->node->left));
                st.push_front(new Pack(1, cur->node));            
            }
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