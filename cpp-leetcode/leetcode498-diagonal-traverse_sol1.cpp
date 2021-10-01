#include<vector>
#include<bits\stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        const int rows = mat.size(); /* 由于1 <= m, n <= 10^4, 故不需要判空 */
        const int cols = mat[0].size();
        vector<int> res;      
        int pathCount = rows + cols - 1;    /* 先算出总的趟数 */    
        int x = 0;
        int y = 0;
        for (int i = 0; i < pathCount; i++)  /* i表示第i趟 */
        {
            if (i % 2 == 0) // 走向: 右上方向
            {
                while (y >= 0 && x < cols)
                {
                    res.push_back(mat[y][x]);
                    y--;
                    x++;
                }
                // 在顶部越界了, 进行相应处理
                if (x < cols) y++;
                else {
                    y = y + 2;
                    x--;
                }
            }
            else {        /* 走向: 左下方向 */
                while (y < rows && x >= 0)
                {
                    res.push_back(mat[y][x]);                    
                    y++;
                    x--;
                }
                // 在底部越界了, 进行相应处理
                if (y < rows) x++;
                else
                {
                    y--;
                    x = x + 2;
                }
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = sol.findDiagonalOrder(mat);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}