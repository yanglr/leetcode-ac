#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/**
 * Definition for a binary tree root->
*/
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curPath;
        dfs(root, targetSum, curPath, res);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int>& curPath, vector<vector<int>>& res)
    {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) /* 走到叶子节点, 就没法继续向下走了 */
        {
            if (root->val == sum) /* 特殊情况, 当前结点的值就是需要找的sum */
            {
                curPath.push_back(root->val);
                res.push_back(curPath);
                curPath.pop_back();    /* Un-choose(回到选这个结点之前的状态), 尝试找下一个 */
            }
            return;
        }
        curPath.push_back(root->val);
        int newSum = sum - root->val;
        dfs(root->left, newSum, curPath, res);
        dfs(root->right, newSum, curPath, res);
        curPath.pop_back();
    }
};

// Test
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(3);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(1);
    TreeNode* n3 = new TreeNode(6);
    TreeNode* n4 = new TreeNode(2);
    TreeNode* n5 = new TreeNode(0);
    TreeNode* n6 = new TreeNode(8);
    TreeNode* n7 = new TreeNode(7);
    TreeNode* n8 = new TreeNode(4);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n4->left = n7;
    n4->right = n8;

    int targetSum = 14;
    auto res = sol.pathSum(root, targetSum);
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }   

    return 0;
}