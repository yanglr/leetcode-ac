#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> dictS;
        unordered_map<char, int> dictT;
        for (auto ch1 : s)
            dictS[ch1]++;
        for (auto ch2 : t)
            dictT[ch2]++;
        
        char res;
        for (auto kvp : dictT)
        {
            char key = kvp.first;
            int value = kvp.second;

            if (kvp.second != dictS[kvp.first])
            {
                res = key;
                break;
            }
        }
     
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abcd", t = "abcde";
    auto res = sol.findTheDifference(s, t);
    cout << res << endl;

    return 0;
}