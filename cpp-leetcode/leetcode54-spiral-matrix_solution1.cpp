#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        if (M.empty()) return {};
        int rows = M.size(); // rows >= 1
        int cols = M[0].size(); // cols >= 1
        int totalCount = rows*cols;
        
        vector<int> res;
        int row = 0;
        int col = 0;
        int rowStep = 0;
        int colStep = 1;

        int rowStartIndex = 0;
        int colStartIndex = -1;
        while (res.size() < totalCount) {
            res.push_back(M[row][col]);
            if (rowStep != 0) {
                int nextRow = row + rowStep;
                if (nextRow == rows) rows--;  // 到达矩阵的下边界, 就开始缩小
                else if (nextRow == rowStartIndex) rowStartIndex++; /* 到达矩阵的上边界, 就开始扩大 */
                else {
                    row = nextRow;
                    continue;
                }
                colStep = -rowStep;
                rowStep = 0;
                col += colStep;
            } else { // colStep != 0
                int nextCol = col + colStep;
                if (nextCol == cols) cols--;  /* 到达矩阵的右边界, 就开始缩小 */
                else if (nextCol == colStartIndex) colStartIndex++; /* 到达矩阵的左边界, 就开始扩大 */
                else {
                    col = nextCol;
                    continue;
                }
                rowStep = colStep;
                colStep = 0;
                row += rowStep;
            }
        }

        return res;
    }
};

// M[0][0] -> M[0][2] (M[0][N-1])
// M[1][c-1] -> M[r-1][c-1]
// M[r-1][c-1] -> M[r-1][0]
// M[r-1][0] -> M[1][0] (r = r-1)
// loop

// Test
int main()
{
    Solution sol;
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = sol.spiralOrder(matrix);
    for (auto &num : res)
        cout << num << " ";  
    
    return 0;
}