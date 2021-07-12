#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string replaceSpaces(string S, int length) {
        if(length > S.size()) return "";
        S = S.substr(0, length);

        string res;
        for(int i=0; i < length; i++)
        {
            if(S[i] != ' ')
                res.push_back(S[i]);
            else {
                res.append("%20");
            }
        }

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "Mr John Smith    ";
    int k = 13;
    auto res = sol.replaceSpaces(str, k);

    cout << res << endl;
    
    return 0;
}
