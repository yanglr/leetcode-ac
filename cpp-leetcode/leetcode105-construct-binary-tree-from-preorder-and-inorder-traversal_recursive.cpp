#include<vector>
#include<unordered_map>
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
    unordered_map<int, int> posDict;
    vector<int> pre, in;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        if (pre.size() != in.size() || pre.empty() || in.empty())
            return nullptr;
        for (int i = 0; i < in.size(); i++)
            posDict[in[i]] = i;
        
        return build(0, pre.size() - 1, 0, in.size() - 1);
    }
    TreeNode* build(int preStart, int preEnd, int inStart, int inEnd)
    {
        if (preStart > preEnd)
            return nullptr;
        int rootVal = pre[preStart]; /* 不能写成 rootVal=pre.front();, 因为数组pre是不变的, 但实际上要处理的区间一直是缩小的, 即 preStart是递增变化的 */
        auto root = new TreeNode(rootVal);
        int k = posDict[rootVal]; // 找到当前的root结点在中序遍历中的位置
        root->left = build(preStart+1, k + preStart - inStart, inStart, k - 1);
        root->right = build(k+1+preStart - inStart, preEnd, k+1, inEnd);

        return root;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};

    auto root = sol.buildTree(pre, in);

    return 0;
}