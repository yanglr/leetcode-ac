#include <algorithm>
#include <string>
#include <vector>
#include <set>       /* 使用set就够了，不一定需要unordered_set */
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> st;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                // 使用i / 3 + "," + j / 3 得到对应第几行第几列的方块(box)
                if (ch != '.'){
                    string val;
                    val.push_back(ch);
                    /* 对于任意一个值不为'.'的字符
                       1.把所在row的信息插入到大九宫格中;
                       2.把所在column的信息插入到大九宫格中;
                       3.把所在的小方块(box)的信息插入到大九宫格中。
                       插入如果失败说明出现了重复。 */
                    if (!st.insert(val + " in row " + to_string(i)).second ||
                        !st.insert(val + " in column " + to_string(j)).second ||
                        !st.insert(val + " in box " + to_string(i / 3) + "," + to_string(j / 3)).second)
                        return false;  /* set插入失败时，表示出现了重复 */
                }
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