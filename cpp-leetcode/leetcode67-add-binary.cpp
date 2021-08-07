#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0)  // 双指针, 让两个数的末位对齐, 两个指针 i, j均从末尾开始走
        {
            int digitA = i >= 0 ? a[i--] - '0' : 0;
            int digitB = j >= 0 ? b[j--] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum >= 2 ? 1 : 0;
            sum = sum >= 2 ? sum - 2 : sum;
            res.append(to_string(sum));
        }
        if (carry == 1)
            res.append("1");
        reverse(res.begin(), res.end());
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string a = "1010", b = "111";
    auto res = sol.addBinary(a, b);
    cout << res << endl;

    return 0;
}