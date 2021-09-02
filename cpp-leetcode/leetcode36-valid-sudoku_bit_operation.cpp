#include <vector>
#include <iostream>
// #include <algorithm>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9); // row[j]表示第j 行的9个数字各自的存在情况，同理于col, boxes
        vector<int> col(9);
        vector<int> boxes(9);

        int shiftInt = 0;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;

                shiftInt = 1 << (board[i][j] - '0');  // 转为二进制，移位结束后目标位为1，其他位均为0
                /* 每个格子若有数字，必为 1 ~ 9，该方法适用于 遍历行/遍历列/遍历box  */
                int boxPos = (i / 3) * 3 + j / 3; //将大数独棋盘分成9个小棋盘，编号0~8

                // 如果当前数字shiftInt在row[j] 或col[i] 或 boxes中已经存在，&运算后不为0，
                // 只有当前数字没出现过，&运算后为0
                if ((col[i] & shiftInt) != 0 || (row[j] & shiftInt) != 0 || (boxes[boxPos] & shiftInt) != 0)
                    return false;

                //第 n 位代表 n 这个数字是否存在(1→存在， 0→不存在)，同理于col[i]  boxes[boxPos]
                row[j] |= shiftInt;
                col[i] |= shiftInt;
                boxes[boxPos] |= shiftInt;
            }
        }
        return true;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> board  /* 不能使用=进行赋值初始化, 自动调用构造函数 */
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    bool isValid = sol.isValidSudoku(board);
    cout << (isValid == true ? "true" : "false") << endl;

    return 0;
}