#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        /** True:
            1、A的个数<2
            2、连续L的个数<=2
        */
        if (count(s.begin(), s.end(), 'A') >= 2)
            return false;
        
        const int len = s.size();
        int lMaxCount = 0;

        for (int i = 0; i < len; i++)
        {
            int lCount = 0;
            if (s[i] == 'L')
            {
                lCount = 1;
                for (int j = i + 1; j < len; j++)
                {
                    if (s[j] == s[i])
                        lCount++;
                    else break;
                }
            }
            lMaxCount = max(lMaxCount, lCount);
        }        
        return (lMaxCount <= 2);
    }
};

// Test
int main()
{
    Solution sol;
    string s = "LLL";
    auto res = sol.checkRecord(s);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}