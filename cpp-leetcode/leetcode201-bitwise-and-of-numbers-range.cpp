#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n)
    {
        /* 题中规定数据范围: m, n中较大值<= 2^31 - 1 = 2147483647 */
        int shiftCount = 0;
        int common = 0;
        GetCommonDigits(m, n, common, shiftCount);
        auto res = common << shiftCount;  // 末位补0
        return res;
    }

    void GetCommonDigits(int a, int b, int& common, int& shiftCount)
    {
        shiftCount = 0;
        while (a != b)
        {
            a = a >> 1;
            b = b >> 1;
            shiftCount++;
        }
        common = a;
    }
};

// Test
int main()
{
    Solution sol;
    int left = 5, right = 2147483647;
    printf("%d", sol.rangeBitwiseAnd(left, right));

    return 0;
}