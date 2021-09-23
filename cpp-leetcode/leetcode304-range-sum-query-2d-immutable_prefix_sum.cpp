#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> _preSum;    
public:
    NumMatrix(const vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size();
        int n = matrix[0].size();
        
        _preSum = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                _preSum[i][j] = matrix[i - 1][j - 1] + _preSum[i - 1][j] + _preSum[i][j - 1] - _preSum[i - 1][j - 1];
            }            
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return _preSum[row2 + 1][col2 + 1] - _preSum[row2 + 1][col1] - _preSum[row1][col2 + 1] + _preSum[row1][col1];
    }
};

// Test
int main()
{
    vector<vector<int>> mat = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    auto M = new NumMatrix(mat);
    int res = M->sumRegion(2, 1, 4, 3); // return 8
    cout << res << endl;
    res = M->sumRegion(1, 1, 2, 2); // return 11
    cout << res << endl;
    res = M->sumRegion(1, 2, 2, 4); // return 12
    cout << res << endl;

    return 0;
}