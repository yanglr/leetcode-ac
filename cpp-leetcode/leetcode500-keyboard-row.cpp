#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> vect {
            "qwertyuiop",
            "asdfghjkl",
            "zxcvbnm"
        };  
        vector<string> res;      
        for (auto word : words)
        {
           AddInResult(vect[0], word, res);
           AddInResult(vect[1], word, res);
           AddInResult(vect[2], word, res);
        }
        return res;
    }
    
    bool isContain(string str, char ch)
    {
        if (find(str.begin(), str.end(), ch) != str.end() || find(str.begin(), str.end(), ch - ('A' - 'a')) != str.end())
            return true;
        return false;
    }

    void AddInResult(string str, string word, vector<string>& res)
    {
        char firstChar = word.front();
        if (isContain(str, firstChar))
        {
            if (word.size() == 1) res.push_back(word);
            else
            {
                int j = 1;
                for (; j < word.size(); j++)
                    if (!isContain(str, word[j])) break;
                if (j == word.size())                        
                    res.push_back(word);
            } 
        }       
    }
};

// Test
int main()
{
	Solution sol;
    vector<string> words = {"a","b"};
	auto res = sol.findWords(words);
    for (auto str : res)
        cout << str << endl;
        
    return 0;
}