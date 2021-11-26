#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        const int eps = 1e-7;
        if (x == 0) return 0;
        double preX = 0; /* preX是区间的边界bound之一, 特定情况下preX和nextX(变量名末尾的X表示横坐标)可能会左右互换. 在区间[0, 1]上开始找，不断调整区间的边界 */
        double nextX = 1;
        while (nextX - preX > eps || preX - nextX > eps)
        {
            preX = nextX;
            nextX = (nextX + x / nextX) / 2.0;
        }
        return (int)nextX; // 转 int
    }
};

// Test
int main()
{
    Solution sol;
    int num = 666;
    auto res = sol.mySqrt(num);
    cout << res << endl;

    return 0;
}