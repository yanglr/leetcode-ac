#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        
        string rs;
        rs.assign(str.rbegin(), str.rend());    // Use reverse iterators   
        
        if (rs == str)
            return true;
        else
            return false;
    }
};

// Below is testing
int main()
{
    Solution sol;
    int num = -101;
    // cout << std::boolalpha << sol.isPalindrome(num) << endl;
    cout << (sol.isPalindrome(num) == true ? "true" : "false") << endl;

    return 0;
}
