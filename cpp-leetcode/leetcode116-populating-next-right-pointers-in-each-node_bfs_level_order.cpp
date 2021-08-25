#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

/** Definition for a Node. */
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        if (root->left == NULL && root->right == NULL)
            return root;
            
        queue<Node*> q;
        q.push({root});    

        while (!q.empty())  
        {
            vector<Node*> curLevel;
            for (int i = q.size(); i > 0; i--)
            {
                Node* p = q.front();   
                q.pop();              
                curLevel.push_back(p);
                if (p->left != NULL)
                    q.push(p->left);

                if (p->right != NULL)
                    q.push(p->right);                                              
            }            
            int curSize = curLevel.size();
            for (int i = 0; i < curSize - 1; i++)  /* 设置每一层的node的next指针的指向 */
                curLevel[i]->next = curLevel[i+1];
            curLevel.back()->next = nullptr;  /* 将当前层最后一个Node的next设为null */
        }
        
        return root;        
    }
};

// Test
int main()
{
    Solution sol;
    Node *root = new Node(1);
    root->left = NULL;
    root->right = new Node(2);
    root->right->left = new Node(3);

    auto res = sol.connect(root);
    
    return 0;
}