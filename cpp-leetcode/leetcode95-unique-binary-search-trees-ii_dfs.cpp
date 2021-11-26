#include<vector>
#include<queue>
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
    vector<TreeNode*> generateTrees(int n) {
        // [1, 2, ... i ... n]
        // 按二叉搜索树的特性进行分组: [1, i-1] i [i+1, n]
        // f(1, n) = { combination(f(1, 1 - 1), f(i + 1, n) ) }, 1 <= i <= n
        if (n == 1)
            return { new TreeNode(1) };
        return helper(1, n);
    }
    vector<TreeNode*> helper(int start, int end)
    {
        vector<TreeNode*> res;
        if (start > end)
        {
            res.push_back(nullptr);
            return res;
        }
        for (int i = start; i <= end; i++)
        {
            auto leftChildren = helper(start, i - 1);
            auto rightChildren = helper(i + 1, end);
            for (auto left : leftChildren)
            {
                for (auto right : rightChildren)
                {
                    auto root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }    
};

// Test
int main()
{
    Solution sol;
    int n = 3;    
    auto res = sol.generateTrees(n);
    for (auto& node : res)
        cout << node->val << " ";

    return 0;
}