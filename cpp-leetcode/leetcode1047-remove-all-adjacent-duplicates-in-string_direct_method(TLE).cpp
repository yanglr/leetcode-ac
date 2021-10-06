#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string s1 = s;
        while (hasDup(s1))
        {
            removeRepeatsOnce(s1);
        }        
        return s1;        
    }
    void removeRepeatsOnce(string& s)
    {
        string str = s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == str[i + 1])
            {
                str.erase(i, 2);
            }
        }

        s = str;
    }
    bool hasDup(string s)
    {
        bool hasDup = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s[i + 1])
                hasDup = true;
        }   
        return hasDup;     
    }    
};

// Test
int main()
{
    Solution sol;
    string s = "abbaca";
    // 输出："ca"
    auto res = sol.removeDuplicates(s);
    cout << res << endl;

    return 0;
}