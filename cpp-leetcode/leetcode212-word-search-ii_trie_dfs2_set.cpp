#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    struct TrieNode {
        int id;
        TrieNode* kids[26];
        TrieNode()
        {
            id = -1; 
            for (int i = 0; i < 26; i++)
                kids[i] = nullptr;
        }
    };
    TrieNode* root;
    unordered_set<int> ids;  /* 存放各个单词在原数组转为set后的虚拟index(set不能直接用index访问) */
    vector<vector<char>> B;
    const int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        B = board;
        root = new TrieNode();
        for (int i = 0; i < words.size(); i++)
            insert(words[i], i);

        for (int i = 0; i < B.size(); i++)
            for (int j = 0; j < B[0].size(); j++)
            {
                int u = B[i][j] - 'a';
                if (root->kids[u])
                    dfs(i, j, root->kids[u]);
            }

        vector<string> res;
        for (auto id : ids)
            res.push_back(words[id]);
        return res;
    }
    
    void insert(string& word, int id)
    {
        auto p = root;
        for (auto& c : word)
        {
            int u = c - 'a';
            if (!p->kids[u])
                p->kids[u] = new TrieNode();
            p = p->kids[u];
        }
        p->id = id;
    }

    void dfs(int x, int y, TrieNode* p)
    {
        if (p->id != -1) ids.insert(p->id);
        char ch = B[x][y];
        B[x][y] = '.';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < B.size() && b >= 0 && b < B[0].size() && B[a][b] != '.')
            {
                int u = B[a][b] - 'a';
                if (p->kids[u])
                    dfs(a, b, p->kids[u]);
            }
        }
        B[x][y] = ch;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> board
    {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};
    auto res = sol.findWords(board, words);
    for (auto str : res)
        cout << str << endl;

    return 0;
}