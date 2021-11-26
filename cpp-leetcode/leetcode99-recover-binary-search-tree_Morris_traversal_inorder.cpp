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
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first = nullptr; /* first: 记录第1个交换的点(逆序对) */
        TreeNode* second; /* second: 记录第2个交换的点 */
        TreeNode* last = nullptr; // last: 当前遍历指针所在位置的上一个node
        while (root != nullptr)
        {
            if (root->left == nullptr) /* 如果没有左子树, 就遍历当前点  */
            {
                if (last != nullptr && last->val > root->val) // 出现了逆序对
                {
                    if (first == nullptr) // 如果是第1个逆序对, 就把逆序对的两个点都存下来
                    {
                        first = last;
                        second = root;
                    }
                    else second = root; /* 如果是第2个逆序对, 只需把逆序对的第2个点都存下来 */
                }    
                last = root; // 把当前点赋值给last, 为下一轮迭代做准备
                root = root->right;
            }
            else // 搭桥: 需要先找到前驱结点
            {
                auto p = root->left;
                while (p->right != nullptr && p->right != root) /* 如果当前结点(root)不为空且没有出现环路, 就继续向右移 */
                    p = p->right;
                if (p->right == nullptr)
                {
                    p->right = root;    /* 搭桥 */
                    root = root->left;
                }
                else
                {
                    // 拆桥
                    p->right = nullptr;
                    if (last != nullptr && last->val > root->val) // 出现了逆序对, 下面的做法与前面相同
                    {
                        if (first == nullptr) 
                        {
                            first = last;
                            second = root;
                        }
                        else second = root;                     
                    }
                    last = root;
                    root = root->right;                    
                }                
            }
        }
        swap(first->val, second->val); // 把错误交换了的结点的值恢复回来
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