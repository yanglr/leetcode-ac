#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        string str = to_string(x);
        int len = str.size();
        int l = 0, r = len - 1;
                       
        while (l < len/2 && r >= len/2)
        {
            if (str[l] != str[r])
            {
                return false;
            }
            
            l++;
            r--;
        }
        return true;
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
