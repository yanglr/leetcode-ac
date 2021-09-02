#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        /* 数组row 存储水平向右方向1 的累加和, 数组col 存储竖直向下方向1 的累加和*/        
        vector<int> row(m);
        vector<int> col(n);
        for (auto op : ops)
        {
            int maxRow = op[0];
            int maxCol = op[1];
            for (int i = 0; i < maxRow; i++)
                row[i]++;
            for (int j = 0; j < maxCol; j++)
                col[j]++;
        }
        int rowIndex = 0, colIndex = 0;
        while (rowIndex < m && row[rowIndex] == row[0]) /* row[0]是当前行的格子的最大值 */
            rowIndex++;
        while (colIndex < n && col[colIndex] == col[0]) /* row[0]是当前列的格子的最大值 */
            colIndex++;
        return rowIndex * colIndex;
    }
};

// Test
int main()
{  
    Solution sol;
    int m = 4, n = 6;
    vector<vector<int>> operations = {{2, 5}, {3, 2}};
    auto res = sol.maxCount(m, n, operations); // 预期结果是4
    cout << res << endl;

    return 0;
}