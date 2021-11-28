#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        vector<string> patArr = getCamelArr(pattern);
        for (auto& q : queries)
        {
            auto qArr = getCamelArr(q);
            bool check = true;
            if (patArr.size() != qArr.size())
                check = false;
            else
            {
                for (int i = 0; i < patArr.size(); i++)
                {
                    if (qArr[i][0] != patArr[i][0])
                    {
                        check = false;
                        break;
                    }

                    unordered_map<char, int> dict1; // 小写字母的词频
                    unordered_map<char, int> dict2;
                    for (auto c : qArr[i])
                        if (c >= 'a' && c <= 'z')
                            dict1[c]++;
                    for (auto c : patArr[i])
                        if (c >= 'a' && c <= 'z')
                            dict2[c]++;                    
                    for (char c = 'a'; c <= 'z'; c++)
                    {
                        if (dict2[c] > dict1[c])
                        {
                            check = false;
                            break;
                        }
                    }
                }               
            }
            res.push_back(check);
        }
        return res;
    }
    vector<string> getCamelArr(string s)
    {
        vector<string> wordList;
        vector<int> upCharIndexes;
        for (int i = 0; i < s.size(); i++)
        {
            // 找到大写字母的index
            if (s[i] >= 'A' && s[i] <= 'Z')
                upCharIndexes.push_back(i);                
        }        
        for (int i = 1; i < upCharIndexes.size(); i++)
        {
             string str = s.substr(upCharIndexes[i-1], upCharIndexes[i] - upCharIndexes[i-1]);
             wordList.push_back(str);
        }
        wordList.push_back(s.substr(upCharIndexes.back(), s.size() - upCharIndexes.back()));
        return wordList;                      
    }    
};

// Test
int main()
{
    Solution sol;
    // vector<string> queries = {"uAxaqlzahfialcezsLfj", "cAqlzyahaslccezssLfj", "tAqlzahavslcezsLwzfj", "eAqlzbxahalcezelsLfj"};
    // string pattern = "AqlzahalcezsLfj";
    vector<string> queries = {"FooBar","FootBall"};
    string pattern = "FoBa";
    auto res = sol.camelMatch(queries, pattern);
    for (auto match : res)
    {
        cout << (match ? "True" : "False") << endl;
    }   

    return 0;
}