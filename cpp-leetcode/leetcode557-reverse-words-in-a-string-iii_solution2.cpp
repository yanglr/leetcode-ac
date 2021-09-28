#include<vector>
#include<string>
#include<algorithm>
#include<sstream> /* 含有stringstream类 */
#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res;        
        // 把word放进vector
        vector<string> words;
        istringstream iss(s);
        while (iss >> s) 
            words.push_back(s);
        for (auto word : words)
        {
            for (int i = word.size() - 1; i >= 0; i--)
                res.push_back(word[i]);
            res.append(" ");
        }
        res.pop_back(); /* 删除最后多余的空格 */      
        return res;
    }
};

// test
int main()
{
    Solution sol;
    string s = "madam lol level civic radar racecar refer";
    auto res = sol.reverseWords(s);
    cout << res << endl;

    return 0;
}