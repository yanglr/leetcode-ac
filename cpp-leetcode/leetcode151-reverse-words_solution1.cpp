#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len0 = s.size();
        string res = "";
        // 1.标准化/归约
        int preSpaceCount = 0;
        for (int i = 0; i < len0; i++)
        {
            if (s[0] == ' ' && s[i] == ' ') preSpaceCount++;
            else break;
        }
        s = s.substr(preSpaceCount, len0 - preSpaceCount);
        int tailSpaceCount = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s.back() == ' ' && s[i] == ' ') tailSpaceCount++;
            else break;
        }        
        s = s.substr(0, s.size() - tailSpaceCount);
        // 把word放进vector
        vector<string> vect;
        istringstream temp(s);  // 类似于cin, 以空格为分隔符将原字符串中的子字符串保存
        while(temp >> s) 
            vect.push_back(s);
        
        for (int i = vect.size() - 1; i >= 0; i--)
        {
            if (i > 0)  res += vect[i] + " ";
            if (i == 0) res += vect[i];
        }     

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "the sky is blue";
    auto res = sol.reverseWords(s);
    cout << res << endl;

    return 0;
}