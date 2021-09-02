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
    vector<int> preorder(Node* root) {
        if (root == nullptr) return {};

        vector<int> nums = {};
        deque<Node*> st; /* 辅助栈, 输出(遍历)顺序: 根 左 右, 于是放入顺序遍历顺序: 右 左 根 */
        st.emplace_front(root);

        while (!st.empty())
        {
            Node* p = st.front();
            nums.push_back(p->val);
            st.pop_front();

            // 逆序遍历children
            const int len = p->children.size();
            for (int i = len-1; i >=0 ; i--)
                st.emplace_front((p->children)[i]);
        }

        return nums;
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