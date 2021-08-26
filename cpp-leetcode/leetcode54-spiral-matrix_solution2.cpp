#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &M) {
        if (M.empty()) return {};    

        vector<int> res;
        int rows = M.size(); // 行数        
        int cols = M[0].size();

        int circles = ((rows < cols ? rows : cols) - 1) / 2 + 1; // 圈数
        for (int k = 0; k < circles; k++)
        {
            for (int i = k; i < cols - k; i++)
                res.push_back(M[k][i]); /* 从左到右, 所在行的index不变, 横坐标++ */
            for (int j = k + 1; j < rows - k; j++)
                res.push_back(M[j][cols - 1 - k]); // M[k+1][y] ==> M[rows-k-1][y];
            for (int m = cols - k - 2; (m >= k) && (rows - k - 1 != k); m--)
                res.push_back(M[rows - k - 1][m]); // 防止重复
            for (int n = rows - k - 2; (n > k) && (cols - k - 1 != k); n--)
                res.push_back(M[n][k]);  // 防止重复
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