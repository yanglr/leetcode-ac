#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> M(n, vector<int>(n, 0));  /* 1 <= n <= 20, 故不需要判空 */

        vector<int> res;        
        int rowBegin = 0;
        int rowEnd = n - 1;
        int colBegin = 0;
        int colEnd = n - 1;

        int num = 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            // 向右遍历
            for (int j = colBegin; j <= colEnd; j++) 
                M[rowBegin][j] = num++;
            rowBegin++;

            // 向下遍历
            for (int j = rowBegin; j <= rowEnd; j++)
                M[j][colEnd] = num++;
            colEnd--;

            if (rowBegin <= rowEnd) // 由于不是方阵, 需要判断还有没有行
            {
                // 向左遍历
                for (int j = colEnd; j >= colBegin; j--)
                    M[rowEnd][j] = num++;
            }
            rowEnd--;

            if (colBegin <= colEnd) // 由于不是方阵, 需要判断还有没有列
            {
                // 向上遍历
                for (int j = rowEnd; j >= rowBegin; j--)
                    M[j][colBegin] = num++;
            }
            colBegin++;
        }

        return M;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 6;
    auto matrix = sol.generateMatrix(6);
    for (auto& rows : matrix) // 遍历每一行
    {
        for (auto& elem : rows) // 输出每一个元素
            cout << elem << "\t";  
        cout << "\n";
    }

    return 0;
}