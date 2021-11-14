#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    unordered_map<Node*, Node*> dict;  /* 哈希表: 记录源点(source node)和它的克隆点(cloned node) */  
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;        
        dfs(node); // 复制所有node

        // 遍历原graph中所有node的所有边
        for (auto& [sNode, cNode] : dict)
        {
            for (auto& nextNode : sNode->neighbors)
                cNode->neighbors.push_back(dict[nextNode]);
        }
        return dict[node];
    }
    void dfs(Node* node)
    {
        dict[node] = new Node(node->val);        
        for (auto& nextNode : node->neighbors)
        {
            if (dict.count(nextNode) == 0)
                dfs(nextNode);
        }
    }
};

// Test
int main()
{
    Solution sol;
    Node n1(1), n2(2), n3(3), n4(4);
    n1.neighbors.push_back(&n2);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n4);
    n4.neighbors.push_back(&n1);
    Node* newNode = sol.cloneGraph(&n1);
    cout << newNode->val << endl;
    cout << newNode->neighbors[0]->val << endl;

    return 0;
}