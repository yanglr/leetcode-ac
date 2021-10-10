#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> rows(numRows);

        if (numRows > 0) rows[0] = {1};
        for (int i = 1; i < numRows; i++)
        {
            vector<int> row(i+1);         // 第 i 行 (行index为i-1) 有 i 个数
            auto preRow = rows[i-1];
            auto curRow = row;

            curRow[0] = curRow[i] = 1;

            for (int j = 1; j < curRow.size() - 1; j++)  // 每一行的首尾两个数不是通过相加得来的
            {
                curRow[j] = preRow[j-1] + preRow[j];
            }
            rows[i] = curRow;            
        }
        return rows[rowIndex];
    }
};

// Below is testing
int main()
{
    Solution sol;
    int numRows = 5;
    auto res = sol.getRow(numRows);

    for (int i = 0; i < res.size(); i++)
        printf("%d ", res[i]);     

    return 0;
}