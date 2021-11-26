#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, int> depths;  /* map: value -> depth */
        unordered_map<int, int> parents; /* map: value -> parent value */
        dfs(root, 0, depths, parents);
        if (depths[x] == depths[y] && parents[x] != parents[y])
            return true;
        return false;
    }
    void dfs(TreeNode* root, int depth, unordered_map<int, int>& depths, unordered_map<int, int>& parents)
    {
        if (root == nullptr) return;
        depths[root->val] = depth;
        if (root->left != nullptr)
        {
            parents[root->left->val] = root->val;
            dfs(root->left, depth + 1, depths, parents);
        }
        if (root->right != nullptr)
        {
            parents[root->right->val] = root->val;
            dfs(root->right, depth + 1, depths, parents);
        }
        return;
    }
};

// Test
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(5);
    auto res = sol.isCousins(root, 2, 3);
    cout << (res ? "True" : "False") << endl;

    return 0;
}