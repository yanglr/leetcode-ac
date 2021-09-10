#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        if (k == 0) return A; /* 题目中k的范围是 k >= 0, 为0时不需要计算, 直接返回A */
        const int len = A.size();
        vector<int> res;
        // 数组A与数k的末位对齐, 对位相加, 记录进位
        int carry = 0;
        int i = len - 1; // i: 数组A中从后往前的指针
        while (k > 0 || i >= 0)
        {
            int sum = (k % 10) + carry;
            sum += (i >= 0 ? A[i] : 0);  // 保证访问A[i]前不越界
            res.push_back(sum % 10);
            carry = sum / 10; // 或写成 carry = (sum <= 9) ? 0 : 1;
            k /= 10; // 删掉数k的最后一位, 继续进行下一轮迭代

            i--;
        }
        if (carry == 1) res.push_back(1); /* 如果最高位产生进位, 需要在最后增加一位, 值为1 */
        reverse(res.begin(), res.end());
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> A = {2, 7, 4};
    int K = 81;

    auto res = sol.addToArrayForm(A, K);
    for (auto &num : res)
        cout << num << endl;  

    return 0;
}
