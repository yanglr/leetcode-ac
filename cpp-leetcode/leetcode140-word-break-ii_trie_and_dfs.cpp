#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    struct TrieNode
    {
        TrieNode* next[26];
        bool isEnd;
        TrieNode()
        {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                next[i] = nullptr;
        }
        // ~TrieNode()
        // {
        //     for (auto node : next) delete node;
        // }           
    };    
    TrieNode* root;
    int failMemo[301];    // 记录dfs中失败时对应的s中的index
    vector<string> res;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        for (auto word : wordDict)
        {
            TrieNode* node = root;
            for (auto ch : word)
            {
                if (node->next[ch - 'a'] == nullptr)
                    node->next[ch - 'a'] = new TrieNode();
                node = node->next[ch - 'a'];
            }
            node->isEnd = true;
        }

        vector<string> curWords;
        dfs(s, 0, curWords);
        return res;
    }

    bool dfs(string& s, int startPos, vector<string>& curWords)
    {
        if (failMemo[startPos] == 1) return false;
        if (startPos == s.size())
        {
            string sen; // 句子
            for (auto& word : curWords)
                sen += word + " ";
            sen.pop_back(); // 删掉最后一个空格
            res.push_back(sen);
            return true;
        }

        TrieNode* node = root;
        bool flag = false;
        for (int i = startPos; i < s.size(); i++)
        {
            if (node->next[s[i] - 'a'] != nullptr)
            {
                node = node->next[s[i] - 'a'];
                if (node->isEnd == true)
                {
                    curWords.push_back(s.substr(startPos, i - startPos + 1));
                    if (dfs(s, i + 1, curWords))
                        flag = true;
                    curWords.pop_back();
                }
            }
            else break;
        }

        if (flag == false) failMemo[startPos] = 1;
        return flag;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "catsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    auto res = sol.wordBreak(s, wordDict); /* 我安装的vs code或minGW或gdb有bug, 结果是{}. 用Dev C++运行正常 */ 
    for (auto& path : res)
        cout << path << endl;
    
    return 0;
}