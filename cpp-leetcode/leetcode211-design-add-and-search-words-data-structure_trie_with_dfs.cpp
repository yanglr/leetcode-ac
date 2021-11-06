#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct TrieNode {
    TrieNode() : kids(26) {}
    ~TrieNode() {
        for (TrieNode* child : kids)
            delete child;
    }
    vector<TrieNode*> kids;
    bool isWord = false;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    void addWord(const string &word) {
        TrieNode* node = &root;
        for (const char c : word)
        {
            const int i = c - 'a';
            if (!node->kids[i])
                node->kids[i] = new TrieNode;
            node = node->kids[i];
        }
        node->isWord = true;
    }

    bool search(const string &word)
    {
        return dfs(word, 0, &root);
    }

private:
    TrieNode root;

    bool dfs(const string &word, int startPos, TrieNode* node)
    {
        if (startPos == word.length()) // 第1种出口
            return node->isWord;
        if (word[startPos] != '.')  // 第2种出口
        {
            TrieNode* next = node->kids[word[startPos] - 'a'];
            if (next == nullptr) return false;
            return dfs(word, startPos + 1, next);
        }

        // 如果word[startPos] == '.', .表示任意一个字母 -> 去26棵子树中搜索
        for (int i = 0; i < 26; i++)
            if (node->kids[i] && dfs(word, startPos + 1, node->kids[i]))
                return true;
        
        return false;
    }
};

// Test
int main()
{
    WordDictionary* wordDict = new WordDictionary();
    wordDict->addWord("bad");
    wordDict->addWord("dad");
    wordDict->addWord("mad");
    bool res = wordDict->search("pad"); // return False
    cout << (res == true ? "True" : "False") << endl;    
    res = wordDict->search("bad"); // return True
    cout << (res == true ? "True" : "False") << endl;     
    res = wordDict->search(".ad"); // return True
    cout << (res == true ? "True" : "False") << endl;     
    res = wordDict->search("b.."); // return True
    cout << (res == true ? "True" : "False") << endl;     

    return 0;
}