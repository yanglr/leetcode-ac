#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        // 题意: 1 <= m, n <= 100, 不需要考虑为空原矩阵是空的情况
        const int m = mat.size();
        const int n = mat[0].size();
        if (m * n != r * c || (m == r && n == c)) return mat;
        /** m*n == r*c时, 想象中把之前的矩阵水平拉直, 然后重新分组
         *  在长度为m*n的数组中每次取c个。
         */
        vector<int> nums;
        for (auto row : mat)
            nums.insert(nums.end(), row.begin(), row.end());

        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
                res[i][j] = nums[c * i + j];
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1,2}, {3,4}};
    int r = 1;
    int c = 4;
    auto res = sol.matrixReshape(mat, r, c);
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }    
    
    return 0;
}
