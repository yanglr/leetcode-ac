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

// 更精彩的解法: 使用先序遍历(bfs), 如果知道了先序遍历的序列化字符串, 是可以唯一确定一棵树的
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val).append(",").append(serialize(root->left)).append(",").append(serialize(root->right));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<TreeNode*> nodes;
        for (int i = 0; i < data.size(); i++)
        {
            int j = i;
            while (j < data.size() && data[j] != ',')
                j++;
            string str = data.substr(i, j - i);
            if (str == "#")
                nodes.push_back(nullptr);
            else nodes.push_back(new TreeNode(stoi(str)));         
            i = j;   
        }
        
        // 以下基于先序遍历递归处理
        return dfs(nodes, 0);        
    }
    TreeNode* dfs(vector<TreeNode*>& nodes, int cur)
    {
        if (nodes[cur] == nullptr) return nullptr; // nodes[cur] 其实就是平时写的root结点
        
        TreeNode* left = dfs(nodes, cur + 1);
        int leftLen = getNum(left);  
        TreeNode* right = dfs(nodes, cur + leftLen + 1);
        nodes[cur]->left = left;
        nodes[cur]->right = right;
        return nodes[cur];
    }
    int getNum(TreeNode* node) /* 在序列化字符串中占的位置数 */
    {
        if (node == nullptr) return 1; // 该node是NULL时, 会表示成"#", 占用1个位置
        return 1 + getNum(node->left) + getNum(node->right);
    }
};

// Test
int main()
{
    TreeNode* root = new TreeNode(1);    
    root->left = new TreeNode(2); 
    root->left->left = new TreeNode(3); 
    root->left->right = new TreeNode(4); 
    root->right = new TreeNode(5); 
    root->right->left = nullptr; 
    root->right->right = new TreeNode(6);     
    Codec ser, deser;
    string serializedStr = ser.serialize(root);
    cout << serializedStr << endl;
    TreeNode* res = deser.deserialize(serializedStr);
    cout << res->val << endl;

    return 0;
}