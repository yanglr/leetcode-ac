#include<iostream>
using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long x1 = max(A, E);  // 左下角的横坐标
        long y1 = max(B, F);  // 左下角的纵坐标
        long x2 = min(C, G);  // 右上角的横坐标
        long y2 = min(D, H);  // 右上角的纵坐标
        long commonArea; // 重叠区域的面积, 不相交时值为0
        if (x1 >= x2 || y1 >= y2)
            commonArea = 0;
        else
            commonArea = max(long(0), (x2 - x1) * (y2 - y1));
        return (C - A) * (D - B) + (G - E) * (H - F) - commonArea;
    }
};

// Test
int main()
{
    Solution sol;
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;
    auto res = sol.computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    cout << res << endl;

    return 0;
}