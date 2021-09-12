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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string res;
        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if (!node) res.append("#,");
            else
            {
                res.append(to_string(node->val)).append(",");
                q.push(node->left);
                q.push(node->right);
            }            
        }
        if (res.size() >=2 && res.substr(res.size() - 2) == "#,")
            res.pop_back(); /* 删掉末尾多余的, */

        return res;
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
            else nodes.push_back(new TreeNode(stol(str)));         
            i = j;   
        }
        
        int i = 0, j = 1;
        while (j < nodes.size())
        {
            if (nodes[i] != nullptr)
            {
                nodes[i]->left = nodes[j];
                nodes[i]->right = nodes[j + 1];
                j += 2; // nodes[i] 有意义时, 才有两个子结点, j 才加上2
            }
            i += 1;
        }      
        return nodes.front();
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