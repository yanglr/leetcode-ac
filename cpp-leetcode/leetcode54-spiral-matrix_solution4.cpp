#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &M) {
        if (M.empty()) return {};
            
        vector<int> res;        
        int rowBegin = 0;
        int rowEnd = M.size() - 1;
        int colBegin = 0;
        int colEnd = M[0].size() - 1;
        while (rowBegin <= rowEnd && colBegin <= colEnd)
        {
            // 向右遍历
            for (int j = colBegin; j <= colEnd; j++) 
                res.push_back(M[rowBegin][j]);
            rowBegin++;

            // 向下遍历
            for (int j = rowBegin; j <= rowEnd; j++)
                res.push_back(M[j][colEnd]);
            colEnd--;

            if (rowBegin <= rowEnd) // 由于不是方阵, 需要判断还有没有行
            {
                // 向左遍历
                for (int j = colEnd; j >= colBegin; j--)
                    res.push_back(M[rowEnd][j]);
            }
            rowEnd--;

            if (colBegin <= colEnd) // 由于不是方阵, 需要判断还有没有列
            {
                // 向上遍历
                for (int j = rowEnd; j >= rowBegin; j--)
                    res.push_back(M[j][colBegin]);
            }
            colBegin++;
        }

        return res;
    }
};

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