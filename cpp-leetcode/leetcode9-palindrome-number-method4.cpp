#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        vector<int> digits;
        while(x)
        {
            digits.push_back(x % 10);
            x /= 10;
        }        
        vector<int> temp = digits;        
        
        reverse(digits.begin(), digits.end());
        if (temp == digits)
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
