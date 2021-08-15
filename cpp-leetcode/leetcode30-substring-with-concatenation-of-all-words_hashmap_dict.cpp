#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordsCount = words.size();
        if (wordsCount == 0) return {};
        int wordLen = words.front().size();
        // 目标哈希表 needWordDict, map: string -> count
        unordered_map<string, int> needDict;
        for (auto word : words)
        {
            if (needDict.find(word) != needDict.end())
                needDict[word]++;
            else needDict[word] = 0;            
        }
        for (int i = 0; i < s.size() - wordLen*wordsCount + 1; i++)
        {
            int count = 0;
            // 构建已有串的哈希表 hasWordsDict
            unordered_map<string, int> hasWordsDict;          
            while (count < wordsCount)
            {
                string curWord = s.substr(i + count * wordLen, wordLen);
                if (needDict.find(curWord) != needDict.end())
                {
                    if (hasWordsDict.find(curWord) != hasWordsDict.end())
                        hasWordsDict[curWord]++;
                    else hasWordsDict[curWord] = 0;
                }
                else break;

                if (hasWordsDict[curWord] > needDict[curWord]) break;
                count++;                                        
            }
            if (count == wordsCount) res.push_back(i);
        }
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "barfoofoobarthefoobarman";
    vector<string> words = {"bar","foo","the"};
    auto res = sol.findSubstring(s, words);
    for(auto num : res)
        cout << num << endl;

    return 0;
}