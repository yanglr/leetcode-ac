#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        unordered_map<char, int> dict = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int len = s.size();

        /* 反向遍历: 如果当前位的字母是最后一位，或者它后一位字母对应的数比它对应的数小的话，
                    则加上当前位的字母对应的数；其他情况则减去当前位的字母对应的数。 */
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