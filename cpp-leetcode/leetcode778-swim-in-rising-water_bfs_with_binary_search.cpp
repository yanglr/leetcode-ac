#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = grid.size();
        int left = 0;
        int right = n * n; // 搜索区间为: [0, n^2)
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (hasPath(grid, n, mid))
                right = mid;
            else left = mid + 1;
        }
        return left;
    }
    bool hasPath(vector<vector<int>>& grid, int n, int t)
    {
        if (grid[0][0] > t) return false;
        queue<int> q; // queue中存储的元素: y * N + x
        vector<int> visited(n * n);
        q.push(0); // 0*N + 0

        while (!q.empty())
        {
            const int x = q.front() % n;
            const int y = q.front() / n;
            q.pop();
            if (x == n - 1 && y == n - 1) return true;
            for (int i = 0; i < 4; i++)
            {
                const int tx = x + dx[i];
                const int ty = y + dy[i];
                if (tx < 0 || ty < 0 || tx >= n || ty >= n || grid[ty][tx] > t)
                    continue;
                const int key = ty * n + tx;
                if (visited[key])
                    continue;
                visited[key] = 1;
                q.push(key);
            }
        }
        return false;
    };
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    auto res = sol.swimInWater(grid);
    cout << res << endl;

    return 0;
}