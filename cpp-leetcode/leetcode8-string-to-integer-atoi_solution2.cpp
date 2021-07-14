#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        stringstream ss;
        int res = 0;
        ss << s;
        ss >> res;
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "-5------+";
    int res = sol.myAtoi(str);
    cout << res << endl;

    return 0;
}