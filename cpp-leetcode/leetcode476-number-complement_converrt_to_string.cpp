#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {    
       string str = toReverseBinary(num);
       return stoi(str, nullptr, 2);      /* 从2进制串转十进制数, 第3个参数2表示二进制 */
    }

    string toReverseBinary(long n)  /* 得到二进制数的补码字符串 */
    {
        string res = "";
        while (n > 0)
        {
            char r = n % 2 == 0 ? '1' : '0';  /* 得到每一位的反转值 */
            res.push_back(r);     /* 记住: 放进去的结果会导致低位在前, 高位在后 */
            n /= 2;
        }
        reverse(res.begin(), res.end());

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