#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result;

        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        // 双指针: 两字符串尾部对齐, 从低位向高位扫描, "越界"就置为0, 使其不影响计算
        while (i >= 0 || j >= 0 || carry > 0) {
            int v1 = i >= 0 ? num1[i] - '0' : 0;
            int v2 = j >= 0 ? num2[j] - '0' : 0;
            int sum = v1 + v2 + carry;
            result.push_back(sum % 10 + '0'); /* 把当前位加到结果数组中, 并更新进位值为下一轮循环做准备 */
            carry = sum / 10;

            i--;
            j--;
        }
        
        reverse(result.begin(), result.end()); /* 由于一开始低位放在数组的前面, 所以需要反转1次 */
        return result;
    }
};

// Test
int main()
{
    Solution sol;
    string num1 = "4591";
    string num2 = "123";
    auto res = sol.addStrings(num1, num2);
    cout << res << endl;

    return 0;
}