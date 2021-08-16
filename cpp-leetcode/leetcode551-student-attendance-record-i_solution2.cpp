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

        int lCount = 0;
        for (auto ch : s)
        {
            if (ch == 'L')
                lCount++;
            else lCount = 0;
            
            if (lCount > 2)
                return false;
        }
        return true;
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