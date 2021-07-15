#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits == "") return {};
        vector<string> res{""};
        
        for(int i=0; i<digits.size(); i++)
        {
            vector<string> temp;  // temp是本轮字符选择完成的结果
            char ch = digits[i];
            string curStr = dict[ch-'0'];

            for(int j = 0; j < curStr.size(); j++)
                for(int k = 0; k < res.size(); k++)
            {
                temp.push_back(res[k]+curStr[j]);   // res[k] 是上一轮字符选择的结果
            }
            res = temp;
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string n = "25";
    vector<string> res = sol.letterCombinations(n);
    
    for(string s : res)
    {
        cout << s << endl;
    }

    return 0;
}