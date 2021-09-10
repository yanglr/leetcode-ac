#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

/**
 * Definition for a binary tree baseTopNode.
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int res = -1;
        while (!q.empty())
        {
            int size = q.size();
            int baseTopNo = q.front().second;
            int curTopNo;

            for (int i = 0; i < size; i++)
            {
                auto topKvp = q.front();
                q.pop();
                auto topNode = topKvp.first;
                curTopNo = topKvp.second;
                auto p = curTopNo - baseTopNo + 1;
                if (topNode->left)
                    q.push({topNode->left, p * 2});
                if (topNode->right)
                    q.push({topNode->right, p * 2 + 1});
            }
            res = max(res, curTopNo - baseTopNo + 1);
        }
        return res;
    }
};
