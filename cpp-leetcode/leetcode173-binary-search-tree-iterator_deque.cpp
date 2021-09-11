#include<vector>
#include<stack>
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

class BSTIterator {
    deque<TreeNode*> st; // 用做stack, top/pop/push 都在尾部进行
public:
    BSTIterator(TreeNode* root) {  /* 0 <= Node.val <= 10^6 */
        TreeNode* p = root;       
        while (p)
        {
            st.push_back(p);
            p = p->left;
        }
    }
    
    // 将指针向右移动，然后返回指针处的val
    int next() {
        auto p = st.back();
        int res = p->val;
        TreeNode* node = p->right; // 刚开始时node是栈的top处结点的right子结点
        st.pop_back();
        while (node)
        {
            st.push_back(node);
            node = node->left;
        }
        return res;       
    }
    // 如果向指针右侧遍历存在数字，则返回 true 
    bool hasNext() {
        return !st.empty();
    }
};

// Test
int main()
{
    TreeNode *root = new TreeNode(6);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(8);
    TreeNode *n3 = new TreeNode(0);
    TreeNode *n4 = new TreeNode(4);
    TreeNode *n5 = new TreeNode(7);
    TreeNode *n6 = new TreeNode(9);
    TreeNode *n7 = new TreeNode(3);
    TreeNode *n8 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n4->left = n7;
    n4->right = n8;

    /**
     * 你的 BSTIterator 对象会被用以下方式初始化和调用:
     * */
    BSTIterator *it = new BSTIterator(root);
    int val = it->next();
    cout << val << endl;
    bool hasNext = it->hasNext();
    cout << (hasNext ? "True" : "False") << endl;

    return 0;
}