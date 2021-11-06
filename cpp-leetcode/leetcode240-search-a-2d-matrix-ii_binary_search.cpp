#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& M, int target) {
        int rows = M.size();
        int cols = M.front().size();
        int i = 0;
        int j = cols - 1;
        bool found = false;
        while (i < rows && j >= 0) /* j >= 0别漏了= */
        {
            if (M[i][j] == target) return true;
            else if (M[i][j] < target) i++;
            else j--;
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
        {1, 4, 7, 11, 15}, 
        {2, 5, 8, 12, 19}, 
        {3, 6, 9, 16, 22}, 
        {10, 13, 14, 17, 24}, 
        {18, 21, 23, 26, 30}
    };

    int k = 5;
    auto res = sol.searchMatrix(M, k);
    cout << (res ? "True" : "False") << endl;

    return 0;
}