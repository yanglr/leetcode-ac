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
    vector<int> in;
    vector<int> post;
    unordered_map<int, int> posDict;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        in = inorder, post = postorder;
        if (in.size() != post.size() || in.empty() || post.empty())
            return nullptr;
        for (int i = 0; i < in.size(); i++)
            posDict[in[i]] = i;
        
        return build(0, post.size() - 1, 0, in.size() - 1);
    }
    TreeNode* build(int postStart, int postEnd, int inStart, int inEnd)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;
        int rootVal = post[postEnd];
        auto root = new TreeNode(rootVal);
        int k = posDict[rootVal];
        root->left = build(postStart, k + postStart - inStart - 1, inStart, k - 1);
        root->right = build(k + postStart - inStart, postEnd - 1, k+1, inEnd);
        return root;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> post = {9, 3, 15, 20, 7};
    vector<int> in = {9, 15, 7, 20, 3};

    auto root = sol.buildTree(post, in);

    return 0;
}