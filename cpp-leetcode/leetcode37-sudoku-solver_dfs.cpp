#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board, 0, 0);
    }
    /* dfs表示第i行第j列是否能合法地填完. 其中i是行索引row, j是列索引col */
    bool dfs(vector<vector<char>>& board, int i, int j)
    {
        if (i == 9) return true; /* 9行(全局)都填好了 */
        if (j == 9) return dfs(board, i + 1, 0); /* 填完了当前行, 换一行继续 */                    
        if (board[i][j] != '.') return dfs(board, i, j + 1); /* 当前格子不为空白格, 表示是已经填好的数字, 就看同行的下一列 */
        for (char ch = '1'; ch <= '9'; ch++)
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
            if (board[row][j] == ch) return false;
        }
        for (int col = 0; col < 9; col++)
        {
            if (board[i][col] == ch) return false;
        }
        int x = i / 3 * 3;
        int y = j / 3 * 3;
        for (int p = 0; p < 3; p++)
        {
            for (int q = 0; q < 3; q++)
            {
                if (board[x + p][y + q] == ch) return false;
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