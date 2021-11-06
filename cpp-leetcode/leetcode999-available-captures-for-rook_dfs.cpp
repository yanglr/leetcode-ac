#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    const int dx[4] = {-1, 0, 0, 1};
    const int dy[4] = {0, 1, -1, 0};
    const int N = 8;
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int pCount = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 'R')
                {
                    // 一旦发现一个 'R', 就检测其上下左右4个方向
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i, ny = j;
                        while (nx >= 0 && nx < N && ny >= 0 && ny < N) /* 如果没越界 */
                        {
                            if (board[nx][ny] == 'B') /* 遇到自己一方的象B时, 停在原处 */
                                break;
                            else if (board[nx][ny] == 'p') /* 遇到对方的卒p时, 进入该格子, 然后停止 */
                            {
                                pCount++;
                                break;
                            }
                            nx += dx[k];
                            ny += dy[k];
                        }
                    }
                    // 题意: 棋盘上最多只有一个 'R' 存在
                    return pCount;
                }
            }
        }
        // 如果棋盘上没有车(R)或棋盘上没有能吃掉的卒
        return 0;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> board = 
    {
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','R','.','.','.','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','p','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'}
    };    
    auto res = sol.numRookCaptures(board);
    cout << res << endl;

    return 0;
}