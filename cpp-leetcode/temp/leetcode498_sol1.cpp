#include<vector>
#include<bits\stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& M) {
        int m = M.size();
        int n = M[0].size();
        vector<int> res;        
        int pathCount = m + n - 1;        
        bool needRev = false;
        for (int x = 0; x < pathCount; x++)
        {
            vector<int> curPath = getPath(x, 0, M, m, n);
            if (!needRev) res.insert(res.end(), curPath.begin(), curPath.end());
            else 
            {
                reverse(curPath.begin(), curPath.end());
                res.insert(res.end(), curPath.begin(), curPath.end());
            }
            needRev = !needRev;
        }
        // dx = -1, dy = 1
        // path0: M[0][0]
        // path1(需反向): M[1][0] -> M[0][1]
        // path2: M[2][0] -> M[1][1] -> M[0][2]
        return res;
    }
    vector<int> getPath(int x, int y, vector<vector<int>>& M, int maxR, int maxC)
    {
        vector<int> path;
        bool isValid = x >= 0 && x < maxC && y < maxR && y >= 0;
        if (isValid)
            path.push_back(M[y][x]);
        for (int i = x - 1; i >= 0; i--)
        {
            int newX = x - 1;
            int newY = y + 1;
            isValid = newX >= 0 && newX < maxC && newY < maxR && newY >= 0;
            if (isValid)
                path.push_back(M[newY][newX]);            
        }
        return path;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = sol.findDiagonalOrder(mat);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}