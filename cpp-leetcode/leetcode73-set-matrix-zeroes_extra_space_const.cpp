#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>> &M) {
        int rows = M.size();
        if (!rows) return;
        int cols = M[0].size();
        if (!cols) return;

        int flag = 2e3;  /* 1 <= m, n <= 200, 故设置一个范围外的flag即可 */
        for (int i = 0; i < rows; i++)     /* 先把需要改的坐标都标上flag, 最后将标flag的位置进行一次性只0 */
            for (int j = 0; j < cols; j++)
                if (M[i][j] == 0)
                {
                    for (int k = 0; k < cols; k++)
                        if (M[i][k] != 0)    // 将同一行不为0的数的位置把值更新为flag
                            M[i][k] = flag;
                    for (int k = 0; k < rows; k++)
                        if (M[k][j] != 0)   // 将同一列不为0的数的位置把值更新为flag
                            M[k][j] = flag;
                }

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (M[i][j] == flag)
                    M[i][j] = 0;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> M = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    sol.setZeroes(M);

    return 0;
}