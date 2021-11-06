#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1; // i: 表示奇数, 1是用于下面循环的奇数初始值
        while (num > 0)
        {
            num -= i;
            i += 2;
        }
        if (num == 0) return true;
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    int num = 14;
    auto res = sol.isPerfectSquare(num);
    cout << (res ? "True" : "False") << endl;

    return 0;
}