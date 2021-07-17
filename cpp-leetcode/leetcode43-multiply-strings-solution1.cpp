#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0');

        for (int i = n2 - 1; i >= 0; i--)
        {
            for (int j = n1 - 1; j >= 0; j--)
            {
                int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = temp % 10 + '0';    // 当前位
                res[i + j] = res[i + j] + temp / 10; /*前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0' */
            }
        }

        for (int i = 0; i < n1 + n2; i++)
            if (res[i] != '0')
                return res.substr(i); // trim掉结果数组中一开始连续的0

        return res;
    }
};

/*
                                      末位对齐
           1  2  3    n1              i = 2
       x   4  5  6    n2              j = 2
           7  3  8
        6  1  5
   4   9   2                
                      结果中最低位index: 5
                      与之对应的高位(carry位)的index: 4 (i+j)
                      分析知product长度: ≤ n1 + n2, 于是结果最末尾元素的index是i+j+1
*/

// Test
int main()
{
    Solution sol;
    string num1 = "123", num2 = "456";
    string res = sol.multiply(num1, num2);
    cout << res << endl;

    return 0;
}