#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* kids[26];
        string word;
        TrieNode() : word("")
        {
            for (int i = 0; i < 26; i++)
                kids[i] = nullptr;
        }
    };

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode *root = buildTrie(words);
        vector<string> res;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
                dfs(board, i, j, root, res);
        }
        return res;
    }

    /** Insert all the words */
    TrieNode* buildTrie(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for (int j = 0; j < words.size(); j++)
        {
            string word = words[j];
            TrieNode* curr = root;
            for (int i = 0; i < word.length(); i++)
            {
                char ch = word[i] - 'a';
                if (curr->kids[ch] == nullptr) 
                    curr->kids[ch] = new TrieNode();
                curr = curr->kids[ch];
            }
            curr->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* p, vector<string>& res) {
        const int m = board.size();
        const int n = board[0].size();
        char ch = board[i][j];
        if (ch == '#' || p->kids[ch - 'a'] == nullptr) return;
        p = p->kids[ch - 'a'];
        if (p->word.size() > 0)
        {
            res.push_back(p->word);
            p->word = "";
        }

        board[i][j] = '#';
        if (i > 0) dfs(board, i - 1, j, p, res);
        if (j > 0) dfs(board, i, j - 1, p, res);
        if (i < m - 1) dfs(board, i + 1, j, p, res);
        if (j < n - 1) dfs(board, i, j + 1, p, res);
        board[i][j] = ch;
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