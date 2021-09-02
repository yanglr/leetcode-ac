#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);

        if (numRows > 0)
        {
            res[0] = {1};
        }

        for (int i = 1; i < numRows; i++)
        {
            vector<int> row(i+1);    // No.i row (index: i-1) havs i nums
            auto preRow = res[i-1];
            auto curRow = row;

            curRow[0] = curRow[i] = 1;

            for (int j = 1; j < curRow.size() - 1; j++)  // The first and last of each row no need to be added from two nums
            {
                curRow[j] = preRow[j-1] + preRow[j];
            }
            res[i] = curRow;            
        }
        return res;
    }
};

// Below is testing
int main()
{
    Solution sol;
    int numRows = 5;
    vector<vector<int>> res = sol.generate(numRows);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");        
    }    

    return 0;
}