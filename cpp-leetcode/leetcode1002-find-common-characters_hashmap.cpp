#include<vector>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int minDict[26]; // 统计每个字母的最小count
        fill(minDict, minDict + 26, INT_MAX);     
        for (int j = 0; j < words.size(); j++) // 将每一个单词进行哈希化, 然后分别算出每个字母的最小count
        {
            string curWord = words[j];
            vector<int> curDict(26, 0); // 26个字母
            for (auto& ch : curWord)
                curDict[ch - 'a']++;
            for (int i = 0; i < 26; i++)
                minDict[i] = min(minDict[i], curDict[i]);         
        } 
        for (int i = 0; i < 26; i++)
        {
            int curCount = minDict[i];
            if (curCount >= 1)
            {
                auto ch = i + 'a';
                string str;
                str.push_back(ch);
                for (int i = 0; i < curCount; i++)
                    res.push_back(str);
            }            
        }        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> words = {"cool", "lock", "cook"};
    auto res = sol.commonChars(words);
    for (auto str : res)
        cout << str << endl;

    return 0;
}