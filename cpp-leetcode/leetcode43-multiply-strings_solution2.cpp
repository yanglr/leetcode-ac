#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1+n2, '0');

        for(int i = n1 - 1; i>=0; i--)
        {
            for(int j = n2 - 1; j>=0; j--)
            {
                int x = num1[i] - '0';
                int y = num2[j] - '0';
                int curSum = x*y + (res[i+j+1] - '0') + (res[i+j] - '0')*10;

                res[i+j+1] = curSum % 10 + '0';
                res[i+j] = (curSum / 10) + '0';
            }
        }

        for(int i = 0; i < n1 + n2; i++)
            if(res[i] != '0') return res.substr(i); // trim掉结果数组中一开始连续的0
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string num1 = "123", num2 = "456";
    string res = sol.multiply(num1, num2);
    cout << res << endl;

    return 0;
}