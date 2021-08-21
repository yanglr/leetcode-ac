#include<algorithm>
#include<string>
#include<vector>
#include<memory>    /* 包含智能指针std::unique_ptr */
#include<iostream>
using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() : _root(new TrieNode()) {}

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode* p = _root.get();
        for (auto ch : word)
        {
            if (!p->children[ch - 'a'])
                p->children[ch - 'a'] = new TrieNode();
            p = p->children[ch - 'a'];
        }
        p->isWord = true;
    }

    /** return: 单词是否在trie 中 */
    bool search(string word)
    {
        const TrieNode* p = find(word);
        return p && p->isWord;  // p != nullptr && p->isWord
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    struct TrieNode
    {
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(26, nullptr) {}
        ~TrieNode()
        {
            for (auto child : children)
                if (child) delete child;
        }
    };
    std::unique_ptr<TrieNode> _root;

    const TrieNode* find(const string &prefix)
    {
        TrieNode* p = _root.get();
        for (auto ch : prefix)
        {
            p = p->children[ch - 'a'];
            if (p == nullptr) break;
        }
        return p;
    }
};

// Test
int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    cout << (trie->search("apple") == true ? "true" : "false") << endl; // returns true
    cout << (trie->search("app") == true ? "true" : "false") << endl;   // returns false
    trie->insert("pple");
    trie->insert("aple");
    trie->insert("pappaple");
    trie->insert("abaple");
    trie->insert("aass");
    trie->insert("avva");
    trie->insert("aaaa");
    cout << (trie->startsWith("app") == true ? "true" : "false") << endl; // return true
    trie->insert("app");
    cout << (trie->search("app") == true ? "true" : "false") << endl; // return true
}