#include<deque>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return {};
        vector<int> res;
        postOrder(root, res);
        
        return res;
    }
    void postOrder(Node* root, vector<int>& res)
    {
        if (root == nullptr) return;
        for (auto child : root->children)
            postOrder(child, res);
        res.push_back(root->val);
    }
};

// Test
int main()
{
    Solution sol;
    
    Node* root = new Node(1);  
    auto child1 = new Node(3);
    auto child11= new Node(5);
    auto child12= new Node(6);
    child1->children.push_back(child11);
    child1->children.push_back(child12);
    root->children.push_back(child1);

    auto child2 = new Node(2);
    auto child3 = new Node(4);
    root->children.push_back(child2);     
    root->children.push_back(child3); 
    
    vector<int> res = sol.postorder(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}