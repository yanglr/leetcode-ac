#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string s1 = "";
        for (auto& ch : paragraph)
        {
            if (isalpha(ch) || ch == ' ' || ch == ',') /* 注意这里逗号","的处理 */
            {
                char newCh;
                if (ch >= 'A' && ch <= 'Z') newCh = ch - 'A' + 'a'; /* 遇到大写字母转小写 */
                else if (ch == ',') newCh = ' ';
                else newCh = ch;
                s1 += newCh;
            }
        }
        stringstream ss(s1);
        unordered_map<string, int> wordDict;
        while (ss >> s1)
        {
            if (find(banned.begin(), banned.end(), s1) == banned.end()) /* 只统计不在banned数组中的单词 */
                wordDict[s1]++;
        }
        string commonWord;
        int maxCount = 0;
        for (auto& kvp : wordDict)
            maxCount = max(maxCount, kvp.second);
        for (auto& kvp : wordDict)
        {
            string word = kvp.first;
            if (kvp.second == maxCount)
                commonWord = word;
        }
        return commonWord;        
    }
};

int main()
{
    Solution sol;
    string s = "a, a, a, a, b,b,b,c, c";
    vector<string> banned = {"a"};
    auto res = sol.mostCommonWord(s, banned);
    cout << res << endl;
    
    return 0;
}