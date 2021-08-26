#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &M) {
        if (M.empty()) return {};
        int m = M.size();    // m >= 1
        int n = M[0].size(); // n >= 1

        vector<int> res;
        int row = 0, col = -1;
        while (true)
        {
            for (int i = 0; i < n; i++) /* 把第1行的每一列的数放进去 */
                res.push_back(M[row][++col]);
            if (--m == 0)  /* 每次减1表示水平向右方向1圈遍历完成, 当发现当前所在行的index为1(回到第2行)时, 直接break */
                break;
            for (int i = 0; i < m; i++) /* 把第1行以外的每一行的最后一列的数放进去 */
                res.push_back(M[++row][col]);
            if (--n == 0) /* 每次减1表示垂直向下1圈遍历完成, 当发现当前所在列的index为1(回到第2列)时, 直接break */
                break;
            for (int i = 0; i < n; i++)
                res.push_back(M[row][--col]);
            if (--m == 0) /* 每次减1表示水平向左方向1圈遍历完成, 当发现当前所在行的index为1(回到第2行)时, 直接break */
                break;
            for (int i = 0; i < m; i++)
                res.push_back(M[--row][col]);
            if (--n == 0) /* 每次减1表示垂直向上1圈遍历完成, 当发现当前所在列的index为1(回到第2列)时, 直接break */
                break;
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