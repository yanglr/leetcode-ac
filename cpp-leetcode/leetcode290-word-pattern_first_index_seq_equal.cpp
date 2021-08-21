#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
/**
 * @Author: https://github.com/yanglr
 * @Date: 2021-08-17 19:32:27
 * @Title: LeetCode290. 单词规律
 * @中文题目: 290. 单词规律
 * @EnglishTitle: 290. Word Pattern
 * @Alias: LC290 - 力扣290
 * @Tag: 字符串
 * Created by 极客学长 on 2021-08-17.
*/
class Solution {
public:
    bool wordPattern(string pat, string s) {
        vector<int> pFirstIndex;
        vector<string> words;        
        vector<int> sFirstIndex;
        for (auto ch : pat)
        {
            int firstIndex = pat.find_first_of(ch);
            pFirstIndex.push_back(firstIndex);
        }
        
        istringstream iss(s);
        while (iss >> s)
            words.push_back(s);
                
        for (auto& w : words)
        {
            auto it = find(words.begin(), words.end(), w);
            if (it != words.end())
                sFirstIndex.push_back(it - words.begin());
        }
        
        return pFirstIndex == sFirstIndex;   
    }
};

// Test
int main()
{
    Solution sol;
    string pattern = "abba", str = "dog cat cat dog";
    auto res = sol.wordPattern(pattern, str);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}