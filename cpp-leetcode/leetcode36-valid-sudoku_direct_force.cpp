#include <algorithm>
#include <string>
#include <vector>
#include <set>       /* 使用set就够了，不一定需要unordered_set */
#include <iterator>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        bool isValid = true;

        // 遍历行
        for (int i = 0; i < 9; i++)
        {
            set<char> st;
            vector<char> rowVec = board[i];
            int dotCount = 0;
            for (int k = 0; k < 9; k++)
            {
                if (rowVec[k] == '.')
                {
                    dotCount++;
                }
                else
                    st.insert(rowVec[k]);
            }
            int uniqueRowChar = st.size();
            if (uniqueRowChar + dotCount != 9)
            {
                isValid = false;
            }
        }

        // 遍历列
        for (int i = 0; i < 9; i++)
        {
            set<char> st;            
            int dotCount = 0;
            for (int k = 0; k < 9; k++)
            {
                if (board[k][i] == '.')
                {
                    dotCount++;
                }
                else
                    st.insert(board[k][i]);
            }
            int uniqueRowChar = st.size();
            if (uniqueRowChar + dotCount != 9)
            {
                isValid = false;
            }
        }

        // 遍历小grid: 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
        for (int si = 0; si <= 6; si += 3)                 
            for (int sj = 0; sj <= 6; sj += 3)
            {
                set<char> st; 
                int dotCount = 0;
                for (int i = si; i < si + 3; i++)
                {
                    for (int j = sj; j < sj + 3; j++)
                    {
                        if (board[i][j] == '.')
                            dotCount += 1;
                        else
                            st.insert(board[i][j]);
                    }
                }
                if (st.size() + dotCount != 9)
                    isValid = false;
            }
        return isValid;
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