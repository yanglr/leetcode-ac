#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(board, i, j, word, 0))
                    return true;
            }                
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int x, int y, string& str, int curPos)
    {
        if (board[x][y] != str[curPos]) return false;
        if (curPos == str.size() - 1) return true;
        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1}; /* 推荐写法: 使用两个定长数组做方向向量, 右/左/上/下 */
        char ch = board[x][y];
        board[x][y] = '*';     /* word中只含有英文字母, 这里用英文字母以外的字符都行, 比如使用星号  */
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size())
            {
                if (dfs(board, newX, newY, str, curPos + 1))
                    return true;
            }
        }
        board[x][y] = ch;

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