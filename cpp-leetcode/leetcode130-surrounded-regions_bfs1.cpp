#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, -1, 1};    
public:
    void solve(vector<vector<char>> &M) {
        if (M.size() == 0 || M[0].size() == 0) return;
        const int n = M.size();
        const int m = M[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && M[i][j] == 'O')
                {
                    // 只要遇到4条边上的大写'o', 就改为$后放入BFS搜索队列
                    M[i][j] = '$';
                    q.push({i, j});
                }
            }
        }
        while (q.size())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a >= 0 && a < n && b >= 0 && b < m && M[a][b] == 'O')
                {
                    M[a][b] = '$';
                    q.push({a, b});
                }
            }
        }
        /* 遍历完成后, 所有与边相邻的大写'o'变成了$。需要此时的$恢复成大写'o', 且将此时还不是$或X的格子修改为$ */
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == '$') M[i][j] = 'O';
                else if (M[i][j] != 'X')
                    M[i][j] = 'X';
            }
        }
        return;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> M {
        {'X', 'X', 'X', 'X'},        
        {'X', 'O', 'O', 'X'},        
        {'X', 'X', 'O', 'X'},        
        {'X', 'O', 'X', 'X'}};

    sol.solve(M);
    for (auto& row : M) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << "\t";  
        cout << "\n";
    }   

    return 0;
}