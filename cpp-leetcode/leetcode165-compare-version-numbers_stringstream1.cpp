#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        if (v1 == v2) return 0;   
             
        istringstream iss1(v1); /* 把每一个stringstream都看作数字+点字符+数字+点字符+... */
        istringstream iss2(v2);
        while (iss1 || iss2)
        {
            char dot;
            long num1 = 0, num2 = 0;
            if (iss1) iss1 >> num1 >> dot;
            if (iss2) iss2 >> num2 >> dot;
            if (num1 != num2)
                return num1 < num2 ? -1 : 1;
        }
        return 0;
    };
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