#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
    int n, m;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
public:
    void solve(vector<vector<char>>& M) {
        n = M.size();
        m = M[0].size();
        if (m == 0 || n == 0) return;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) /* 只对边界4条边上值是大写'o'的格子进行dfs */
                {
                    if (M[i][j] == 'O') dfs(M, i, j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (M[i][j] == 'O') M[i][j] = 'X'; /* 留下来的大写'o'的格子是非边界上(内部)的大'o', 且不与边界的大'o'相连, 最终必然会变成X */
                else if (M[i][j] == '$')
                    M[i][j] = 'O';              
            }
        }        
    }
    /* dfs: 把(边界4条边上)所有值是大写'o'的格子标记为$, 并dfs遍历其上下左右4个邻居 */
    void dfs(vector<vector<char>>& M, int x, int y)
    {
        if (M[x][y] != 'O') return;
        M[x][y] = '$';
        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || M[a][b] != 'O') continue;
            dfs(M, a, b);
        }  
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