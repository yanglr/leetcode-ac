#include<vector>
#include<unordered_set>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

struct TrieNode {
    vector<TrieNode *> kids;
    const string *word;
    TrieNode() : kids(26), word(nullptr) {}
    ~TrieNode()
    {
        for (auto node : kids) delete node;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;
        for (const string &word : words)
        {
            TrieNode *cur = &root;
            for (char c : word)
            {
                auto &next = cur->kids[c - 'a'];
                if (!next) next = new TrieNode();
                cur = next;
            }
            cur->word = &word;
        }

        const int n = board.size();
        const int m = board[0].size();
        vector<string> res;

        function<void(int, int, TrieNode *)> dfs = [&](int x, int y, TrieNode *node) {
            if (x < 0 || x == m || y < 0 || y == n || board[y][x] == '#')
                return;

            const char cur = board[y][x];
            TrieNode *next_node = node->kids[cur - 'a'];

            // 剪枝
            if (!next_node) return;

            if (next_node->word)
            {
                res.push_back(*next_node->word);
                next_node->word = nullptr;
            }

            board[y][x] = '#';
            dfs(x + 1, y, next_node);
            dfs(x - 1, y, next_node);
            dfs(x, y + 1, next_node);
            dfs(x, y - 1, next_node);
            board[y][x] = cur;
        };

        // 尝试所有的路径
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dfs(j, i, &root);

        return res;
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