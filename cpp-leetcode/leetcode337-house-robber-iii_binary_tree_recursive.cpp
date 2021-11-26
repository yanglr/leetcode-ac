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
    unordered_map<TreeNode*, int> robDict; /* 记忆化 */
    unordered_map<TreeNode*, int> noRobDict;    
public:
    int rob(TreeNode* root) {
        return dfs(root, 1);
    }
    int dfs(TreeNode* node, int flag) /* flag: 1表示可抢可不抢, 0表示后续不能抢 */
    {
        if (node == nullptr) return 0;
        if (flag == 0 && noRobDict.find(node) != noRobDict.end())
            return noRobDict[node];
        if (flag == 1 && robDict.find(node) != robDict.end())
            return robDict[node];

        int res;
        if (flag == 0)
            res = dfs(node->left, 1) + dfs(node->right, 1);
        else
        {
            int option1 = node->val + dfs(node->left, 0) + dfs(node->right, 0);
            int option2 = dfs(node->left, 1) + dfs(node->right, 1);
            res = max(option1, option2);
        }

        if (flag == 0)
            noRobDict[node] = res;
        else robDict[node] = res;

        return res;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);    
    
    auto res = sol.rob(root);
    cout << res << endl;

    return 0;
}