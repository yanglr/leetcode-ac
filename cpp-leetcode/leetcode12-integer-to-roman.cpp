#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        vector<int> vals = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        /* 注意: 只有I,X,C可以在临近大小值的左侧位置, 剩下的 V,L,D,M不能 */
        vector<string> strs = {"M", "CM","D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV","I"};
        for(int i=0; i < vals.size(); i++)
        {
            while(num >= vals[i])  /* 循环出口：只要够减，就继续 */
            {
                num -= vals[i];
                res.append(strs[i]);
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 4999;
    string res = sol.intToRoman(n);
    cout << res << endl;

    return 0;
}