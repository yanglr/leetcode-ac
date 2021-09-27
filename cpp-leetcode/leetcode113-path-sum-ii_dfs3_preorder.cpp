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
    vector<vector<int>> res;
    int _targetSum;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        _targetSum = targetSum;
        vector<int> curPath;
        int sum = 0;
        preOrder(root, _targetSum, curPath, sum);
        return res;
    }
    void preOrder(TreeNode* root, int targetSum, vector<int>& curPath, int curSum)
    {
        if (root == nullptr) return;
        curSum += root->val;
        curPath.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr)
        {
            if (curSum == targetSum) res.emplace_back(curPath);
            curPath.pop_back();
            return;
        }

        preOrder(root->left, targetSum, curPath, curSum);
        preOrder(root->right, targetSum, curPath, curSum);
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