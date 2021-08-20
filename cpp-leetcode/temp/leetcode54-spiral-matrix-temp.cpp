#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& M) {
        if (M.empty()) return {};
        int r = M.size(); // rowCount >= 1
        int c = M[0].size(); // colCount >= 1
        int allCount = r*c;
        vector<int> res;
        if (r == 1)
        {
            for (int i = 0; i < c; i++)
            {
                res.push_back(M[0][i]);
            }
            return res;
        }
        if (c == 1)
        {
            for (int i = 0; i < r; i++)
            {
                res.push_back(M[i][0]);
            }
            return res;
        }               

        while (allCount > 0)
        {            
            int offset = 0;
            while (r >= 1 && c >= 1)
            {
                getRectEdgeSeq(r, c, offset, M, res, allCount);                              
            }            
        }

        return res;
    }

    void getRectEdgeSeq(int& r, int& c, int& offset, vector<vector<int>> M, vector<int> &res, int &allCount)
    {
        for (int i = 0; i < c - offset; i++)
        {
            if (allCount != 0)
            {
                res.push_back(M[0 + offset][i + offset]);
                allCount--;
                if (M[0 + offset][i + offset] == 6) cout << "found A";
            }
        }
        // 如果能形成矩形
        if (c >= 2 && r >= 2)
        {
            for (int j = 1; j < r - 1 - offset; j++)
            {
                if (allCount != 0)
                {
                    res.push_back(M[j + offset][c - 1 - offset]);
                    if ((M[j + offset][c - 1 - offset]) == 6) cout << "found B";
                    allCount--;
                }
            }
            for (int i = c - 1 - offset; i >= 0; i--)
            {
                if (allCount != 0)
                {
                    res.push_back(M[r - 1 - offset][i]);
                    if (M[r - 1 - offset][i] == 6) cout << "found C\n";
                    allCount--;
                }
            }
            for (int j = r - 2 - offset; j > 0; j--)
            {
                if (allCount != 0)
                {
                    res.push_back(M[j - offset][0 + offset]);
                    if (M[j - offset][0 + offset] == 6) cout << "found D";                    
                    allCount--;
                }
            }
        }
        r--;
        c--;
        offset++;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> M = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    auto res = sol.spiralOrder(M);
    for (auto num : res)
        cout << num << endl;

    return 0;
}