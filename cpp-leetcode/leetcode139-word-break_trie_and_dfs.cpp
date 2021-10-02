#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* next[26];
    bool isEnd;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
        isEnd = false;
    }
};
class Solution {
    TrieNode* root;
    int failMemo[301]; // 记录dfs中失败时对应的s中的index
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        // 建树
        for (auto& word : wordDict)
        {
            TrieNode* p = root;
            for (auto& ch : word)
            {
                if (p->next[ch - 'a'] == nullptr)
                    p->next[ch - 'a'] = new TrieNode();
                p = p->next[ch - 'a'];                   
            }
            p->isEnd = true;            
        }
        return dfs(s, 0);
    }
    bool dfs(string& s, int startPos)
    {
        if (failMemo[startPos] == 1) return false;        
        if (startPos == s.size()) return true;
        TrieNode* p = root;        
        for (int i = startPos; i < s.size(); i++)
        {
            if (p->next[s[i] - 'a'] != nullptr)
            {
                p = p->next[s[i] - 'a'];
                if (p->isEnd == true && dfs(s, i+1))
                    return true;   
            }
            else break;   
        }
        failMemo[startPos] = 1;
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    // 预期输出: true
    auto res = sol.wordBreak(s, wordDict);
    cout << (res == true ? "true" : "false");

    return 0;
}
