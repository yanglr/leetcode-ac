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
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<int, vector<pair<int, int>>> dict; /* x -> array of (y, val), dict size: 不同x值的个数 */
    int minX = 1000;   /* 记录最左边结点的横坐标x, 为了方便后面从哈希表中找到同一条竖直扫描线上的点 */ 
public:
    vector<vector<int>> verticalTraversal(TreeNode* root)
    {
        vector<vector<int>> res;
        dfs(root, 0, 0);
        for (int i = 0; i < dict.size(); i++) /* i: 不同x值的个数 */
        {
            int x = minX + i;
            auto cmp = [](pair<int, int>& p1, pair<int, int>& p2)
            {
                if (p1.first != p2.first)
                    return (p1.first > p2.first);
                return p1.second < p2.second;
            };
            auto kvp = dict[x];  // array of (y, val) for given x               
            sort(kvp.begin(), kvp.end(), cmp);
            vector<int> vLine;             
            for (int j = 0; j < kvp.size(); j++)
                vLine.push_back(kvp[j].second);
            res.push_back(vLine);            
        }
        return res;
    }
    void dfs(TreeNode* root, int x, int y)
    {
        if (!root) return;
        dict[x].push_back({y, root->val});
        minX = min(minX, x); /* 与主函数verticalTraversal()中的语句 int x = minX + i; 配合使用 */
        dfs(root->left, x - 1, y - 1);
        dfs(root->right, x + 1, y - 1);
    }
};

// Test
int main()
{
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = nullptr;

    auto res = sol.verticalTraversal(root);    
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }

    return 0;
}