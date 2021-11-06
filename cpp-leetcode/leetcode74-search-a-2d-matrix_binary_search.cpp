#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {  
public:  
    bool searchMatrix(vector<vector<int>>& M, int target) {  
        const int rows = M.size();
        const int cols = M.front().size();
        int i = 0;
        int j = cols - 1;
        bool found = false;
        while (i < rows && j >= 0) /* j >= 0别漏了= */
        {
            if (M[i][j] == target) return true;
            else if (M[i][j] < target) i++; // 如果矩阵右上角的值不大于target，水平线行数+1  
            else j--; // 如果矩阵右上角的值比target大，竖直线列数-1   
        }
        return found;
    }  
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> M
    {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int k = 3;
    auto res = sol.searchMatrix(M, k);
    cout << (res ? "True" : "False") << endl;

    return 0;
}