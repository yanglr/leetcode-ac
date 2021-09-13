#include <vector>
#include <iostream>
using namespace std;

class Solution {
    vector<vector<char>> M;
    string str;
public:
    bool exist(vector<vector<char>>& board, string word) {
        M = board;
        str = word;
        int m = M.size();
        int n = M[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(i, j, visited, 0))
                    return true;
            }                
        }
        return false;
    }
    bool dfs(int x, int y, vector<vector<int>>& visited, int curPos)
    {
        if (curPos == str.size()) return true;
        int m = M.size();
        int n = M[0].size();        
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (visited[x][y] == 1) return false;
        if (M[x][y] != str[curPos]) return false;
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // 右/左/上/下
        visited[x][y] = 1;
        for (auto dir : dirs)
        {
            auto dirX = dir.first;
            auto dirY = dir.second;
            if (dfs(x + dirX, y + dirY, visited, curPos + 1)) return true;
        }
        visited[x][y] = 0;

        return false;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> board 
    {
        {'A', 'B', 'C', 'E'}, 
        {'S', 'F', 'C', 'S'}, 
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";

    bool isValid = sol.exist(board, word);
    cout << (isValid == true ? "true" : "false") << endl;

    return 0;
}