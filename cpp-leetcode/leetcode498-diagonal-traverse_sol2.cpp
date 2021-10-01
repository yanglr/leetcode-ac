#include<vector>
#include<bits\stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if (mat.empty()) return {};
        int height = mat.size();
        int width = mat[0].size();
        vector<int> res;
        int direction = -1; // ↗方向(up): -1, ↙方向(down): 1
        int y = 0, x = 0;
        while (true)
        {
            // 先处理4种越界情况
            if (x >= width)
            {
                y += 2;
                x -= 1;
                direction = -direction;
                continue;
            }
            if (y >= height)
            {
                y -= 1;
                x += 2;
                direction = -direction;
                continue;
            }
            if (y < 0)
            {
                y += 1;
                direction = -direction;
                continue;
            }
            if (x < 0)
            {
                x += 1;
                direction = -direction;
                continue;
            }
            res.push_back(mat[y][x]);
            if (y == height - 1 && x == width - 1)
                return res;
            y += direction;
            x -= direction;
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto res = sol.findDiagonalOrder(mat);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}