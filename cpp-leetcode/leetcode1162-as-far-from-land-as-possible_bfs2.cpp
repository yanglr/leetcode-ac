#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    const int dx[4] = {0, 1, 0, -1};
    const int dy[4] = {1, 0, -1, 0};    
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int N = grid.size();
        deque<pair<int, int>> q;
        int d[N][N];
        for (auto& row : d)
            fill(row, row + N, 1000);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                if (grid[i][j] == 1)
                {
                    q.push_back(make_pair(i, j));
                    d[i][j] = 0;
                }            
        }
        while (!q.empty())
        {
            auto kvp = q.front();
            q.pop_front();
            for (int i = 0; i < 4; i++)
            {
                int newX = kvp.first + dx[i], newY = kvp.second + dy[i];
                if (newX < 0 || newX >= N || newY < 0 || newY >= N)
                    continue;

                if (d[newX][newY] > d[kvp.first][kvp.second] + 1)
                {
                    d[newX][newY] = d[kvp.first][kvp.second] + 1; 
                    q.push_back(make_pair(newX, newY));
                }
            }
        }
        int res = -1;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0 && d[i][j] <= 200)
                    res = max(res, d[i][j]);
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> grid = 
    {
        {1, 0, 1}, 
        {0, 0, 0}, 
        {1, 0, 1}
    };
    auto res = sol.maxDistance(grid);
    cout << res << endl;

    return 0;
}