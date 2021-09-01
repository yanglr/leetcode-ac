#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        if (v1 == v2)
            return 0;

        auto strArr1 = split(v1, '.');
        auto strArr2 = split(v2, '.');

        int maxLen = strArr1.size() >= strArr2.size() ? strArr1.size() : strArr2.size();
        for (int i = 0; i < maxLen; i++)
        {
            int digit1 = (i >= strArr1.size()) ? 0 : stoi(strArr1[i]);
            int digit2 = (i >= strArr2.size()) ? 0 : stoi(strArr2[i]);

            if (digit1 == digit2)
                continue;

            return (digit1 > digit2) ? 1 : -1;
        }

        return 0;        
    }
    
    vector<string> split(string s, const char sep)
    {
        if (find(s.begin(), s.end(), sep) == s.end())
            return {s};

        vector<string> res;               
        auto firstIt = find(s.begin(), s.end(), sep);
        res.push_back(s.substr(0, firstIt - s.begin()));  /* 放入字符串s开头到第1个sep字符的子串 */
        for (int i = 0; i < s.size(); i++)
        {
            string digitStr;
            int curSepPos = 0;
            int preStartPos = 0;
            if (s[i] == sep)
            {
                curSepPos = i;
                preStartPos = curSepPos + 1;

                digitStr = s.substr(preStartPos, curSepPos - preStartPos);
                res.push_back(digitStr);
            }
        }        

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string version1 = "7.5.2.4", version2 = "7.5.3";
    auto res = sol.compareVersion(version1, version2);
    cout << res << endl;
    
    return 0;
}