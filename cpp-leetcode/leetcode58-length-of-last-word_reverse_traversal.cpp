#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        s.erase(s.find_last_not_of(' ')+1);    // Trim尾部的空格
        s.erase(0, s.find_first_not_of(' '));  // Trim开头的空格
        int lastSpaceIndex = -1;
        int res;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
            {
                lastSpaceIndex = i;
                res = s.size() - 1 - (i+1) + 1;
                break;
            }
        }
        if (lastSpaceIndex == -1) return s.size();
        return res;
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