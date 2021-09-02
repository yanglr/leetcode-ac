#include <string>
#include <algorithm>
#include <bitset>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int theXor = x ^ y; /* xor是^的等价运算符, 是C++关键字, 所以这里使用theXor避免语法错误 */
        string xorStr = toBinary(theXor);
        return count(xorStr.begin(), xorStr.end(), '1'); 
    }
    string toBinary(long n)
    {
        return bitset<64>(n).to_string();
    }    
};

// Test
int main()
{
    Solution sol;
    int x = 1, y = 4;
    auto res = sol.hammingDistance(x, y);
    cout << res << endl;

    return 0;
}