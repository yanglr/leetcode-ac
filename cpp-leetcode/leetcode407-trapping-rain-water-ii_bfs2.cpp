#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& H) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; /* 小顶堆q, 堆中存储 pair of {h, n*x + y} */
        int rows = H.size(), cols = H[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int minimum = INT_MAX;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (!(i==0 || i==rows-1 || j==0 || j==cols-1)) continue;
                q.push({H[i][j], i * cols + j});
                visited[i][j] = true;
                minimum = min(minimum, H[i][j]);
            }
        }        
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int res = 0;
        while (!q.empty())
        {
            pair<int, int> val = q.top();
            q.pop();
            int height = val.first;
            int x = val.second / cols;
            int y = val.second % cols;
            minimum = max(minimum, height);
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= rows || nx < 0 || ny < 0 || ny >= cols || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                if (H[nx][ny] < minimum)
                    res += minimum - H[nx][ny];
                q.push({H[nx][ny], nx * cols + ny});
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> nums = {{1, 4, 3, 1, 3, 2}, {3, 2, 1, 3, 2, 4}, {2, 3, 3, 2, 3, 1}};
    auto res = sol.trapRainWater(nums);
    cout << res << endl;

    return 0;
}