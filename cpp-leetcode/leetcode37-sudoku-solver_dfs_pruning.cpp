#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i == 9) return true;
        if (j == 9)
            return dfs(board, i + 1, 0);
        if (board[i][j] != '.')
            return dfs(board, i, j + 1);

        for (int ch = '1'; ch <= '9'; ch++)
        {
            if (!isValid(board, i, j, ch)) continue;
            board[i][j] = ch;
            if (dfs(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
    bool isValid(vector<vector<char>>& board, int i, int j, char ch)
    {
        for (int row = 0; row < 9; row++)
        {
            if (row != i && board[row][j] == ch) return false;
        }
        for (int col = 0; col < 9; col++)
        {
            if (col != j && board[i][col] == ch) return false;
        }
        int x = i / 3 * 3;
        int y = j / 3 * 3;
        for (int p = x; p < x + 3; p++)
        {
            for (int q = y; q < y + 3; q++)
            {
                if ((p != i || q != j) && board[p][q] == ch) return false;
            }            
        }
        return true;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> board /* 不能使用=进行赋值初始化, 自动调用构造函数 */
    {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, 
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, 
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, 
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, 
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, 
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, 
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    sol.solveSudoku(board);
    for (auto& rows : board) // 遍历每一行
    {
        for (auto& elem : rows) // 输出每一个元素
            cout << elem << "\t";  
        cout << "\n";
    }    

    return 0;
}