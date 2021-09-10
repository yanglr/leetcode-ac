#include<queue>
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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q; // 队列q: 存储TreeNode及其在满二叉树中对应的编号(从1开始, root编号为1)
        q.push({root, 1});
        int res = -1;
        while (!q.empty())
        {
            int size = q.size();
            int baseTopNum = q.front().second; // Num表示No., 在这表示编号
            int curTopNum;

            for (int i = 0; i < size; i++) /* 这个size 不能直接取q.size(), 而是需要提前取到, 否则结果不对 */
            {
                auto topKvp = q.front();
                q.pop();
                auto topNode = topKvp.first;
                curTopNum = topKvp.second;
                auto p = curTopNum - baseTopNum + 1; // 计算出当前队头queue_front处的结点编号
                if (topNode->left)
                    q.push({topNode->left, p * 2});
                if (topNode->right)
                    q.push({topNode->right, p * 2 + 1});
            }
            res = max(res, curTopNum - baseTopNum + 1);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(3);
    TreeNode *n2 = new TreeNode(6);
    TreeNode *n3 = new TreeNode(3);
    TreeNode *n4 = new TreeNode(5);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n3->left = NULL;
    n3->right = NULL;
    n4->left = NULL;
    n4->right = NULL;   

    auto res = sol.widthOfBinaryTree(root);
    cout << res << endl;    

    return 0;
}