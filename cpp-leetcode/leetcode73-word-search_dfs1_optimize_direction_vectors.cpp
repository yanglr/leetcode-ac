#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, i, j, visited, word, 0))
                    return true;
            }                
        }
        return false;
    }
    // 是否能找到index = curPos处的字符, curPos: 在目标单词中的index
    bool dfs(vector<vector<char>>& board, int x, int y, vector<vector<int>>& visited, string& word, int curPos)
    {
        if (curPos == word.size()) return true;
        int m = board.size();
        int n = board[0].size();        
        if (x < 0 || x >= m || y < 0 || y >= n) return false;
        if (visited[x][y] == 1) return false;
        if (board[x][y] != word[curPos]) return false;

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1}; /* 方向变量不使用vector<pair>, 速度会变快, 依次表示右/左/上/下 */
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {
            if (dfs(board, x + dx[i], y + dy[i], visited, word, curPos + 1)) return true;
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