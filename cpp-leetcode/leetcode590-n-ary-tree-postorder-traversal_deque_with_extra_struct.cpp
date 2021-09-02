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

struct Pack {
    int op; /* 0, to visit (表示还需要后续处理); 1, visited/print/save (不需要后续处理了, 就想取里面的值)  */
    Node* node;
    Pack(int op, Node* node) {
        this->op = op;
        this->node = node;
    }
};

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        deque<Pack*> st;
        st.push_front(new Pack(0, root));
        
        while (!st.empty())
        {
            Pack* cur = st.front(); // 先front(), 再pop
            st.pop_front();
            if (cur->node == nullptr)
                continue; 
            if (cur->op == 1)
                res.push_back(cur->node->val);
            else
            {   
                /* 基于deque的辅助栈, 要求每一个结点及其子树的输出(遍历)顺序: 左 右 根, 于是放入顺序遍历顺序: 根 右 左 */
                st.push_front(new Pack(1, cur->node));  
                // 反向for loop
                for (int i = (cur->node->children).size() - 1; i >= 0; i--)
                    st.push_front(new Pack(0, cur->node->children[i]));                       
            }
        }
        return res;
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