#include<string>
#include<iostream>
#include<sstream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        string curWord;
        istringstream iss(s); 
        while (iss >> s) /* 循环结束时, curWord成为最后一个单词 */
            curWord = s;
        return curWord.size();        
    }
};

// Test
int main()
{
    Solution sol;
    string str = "   fly me   to   the moon  ";   
    auto res = sol.lengthOfLastWord(str);
    cout << res << endl;

    return 0;
}