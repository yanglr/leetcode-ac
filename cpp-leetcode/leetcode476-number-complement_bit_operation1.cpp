#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int h = 0;  // 记录几次方
        while (num > 0)
        {
            if(num % 2 == 0) res += pow(2, h);  /* 该位为0, 就取反当1来算 */
            h++;
            num /= 2;
        }
        
        return res;
    } 
};

// Test
int main()
{
    Solution sol;
    int num = 5;
    auto res = sol.findComplement(num);
    cout << res << endl;

    return 0;
}