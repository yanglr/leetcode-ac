#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& M) {
        int r = M.size();
        int c = M[0].size();
        vector<vector<int>> N = M;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (N[i][j] == 0)
                    setRelatedCellsToZero(i, j, r, c, M);
            }            
        }        
    }
    void setRelatedCellsToZero(int i, int j, int r, int c, vector<vector<int>>& M) 
    {   // M[i][j] = 0
        for (int k = 0; k < c; k++)
            M[i][k] = 0;
        for (int k = 0; k < r; k++)
            M[k][j] = 0;      
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> M = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    sol.setZeroes(M);

    return 0;
}