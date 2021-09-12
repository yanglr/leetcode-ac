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

// 先序遍历2
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";
        return to_string(root->val).append(",").append(serialize(root->left)).append(",").append(serialize(root->right));
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        for (int i = 0; i < data.size(); i++)
        {
            int j = i;
            while (j < data.size() && data[j] != ',')
                j++;
            string str = data.substr(i, j - i);
            q.push(str);         
            i = j;   
        }
        
        // 以下基于先序遍历递归处理
        return dfs(q);        
    }
    TreeNode* dfs(queue<string>& q)
    {
        string cur = q.front();
        q.pop();
        
        if (cur=="#") return nullptr;
        TreeNode* root = new TreeNode(stoi(cur));
        
        TreeNode* left = dfs(q);        
        TreeNode* right = dfs(q);
        root->left = left;
        root->right = right;
        return root;
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