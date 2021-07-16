#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int dict[100] = {};    /* X的ASCII码是88, 长度给100够了 */
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;      
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;

        int len = s.size();
        for(int i = len - 1; i >= 0; i--)
        {
            if((i == len - 1) || dict[s[i]] >= dict[s[i+1]])
                sum += dict[s[i]];
            else sum -= dict[s[i]];
        }
        return sum;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "LVIII";
    auto res = sol.romanToInt(str);
    cout << res << endl;

    return 0;
}