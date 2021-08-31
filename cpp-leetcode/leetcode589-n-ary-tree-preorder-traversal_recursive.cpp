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
    vector<int> preorder(Node* root) {
        vector<int> nums = {};
        preOrder(root, nums);
        return nums;
    }
    void preOrder(Node* root, vector<int>& nums)
    {
        if (root == nullptr) return;
        nums.emplace_back(root->val);
        for (auto child : root->children)
            preOrder(child, nums);
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
	
	vector<int> res = sol.preorder(root);
    for (auto num : res)
        cout << num << endl;    

    return 0;
}