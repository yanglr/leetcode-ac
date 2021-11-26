#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
private:
    struct Node {
        int idx;
        vector<Node*> children;
        Node() : idx(-1), children(26, nullptr) {}
    };
    struct Trie {
        Node* root;
        Trie() : root(new Node()) {}
        void insert(string& word, int idx)
        {
            Node* p = root;
            for (char& c : word) {
                c -= 'a';
                if (p->children[c] == nullptr)
                {
                    p->children[c] = new Node();
                }
                p = p->children[c];
            }
            p->idx = idx;
        }
    };    
public:
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        unordered_map<string, vector<int>> cache;
        const int n = big.size();
        const int m = smalls.size();
        vector<vector<int>> res(m);

        Trie trie = Trie();
        // 构造前缀树
        for (int i = 0; i < m; i++)
        {
            trie.insert(smalls[i], i);
        }
        for (int i = 0; i < n; i++)
        {
            int j = i;
            Node* node = trie.root;
            while (j < n && node->children[big[j] - 'a'])
            {
                node = node->children[big[j] - 'a'];
                if (node->idx != -1)
                {
                    res[node->idx].push_back(i);
                }
                j++;
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string big = "mississippi";
    vector<string> smalls = {"is", "ppi", "hi", "sis", "i", "ssippi"};
    auto res = sol.multiSearch(big, smalls);   
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }      

    return 0;
}