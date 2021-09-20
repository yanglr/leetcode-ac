#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int res = 0;
    unordered_set<int> colSet;
    unordered_set<int> diffSet; /* \ 对角线(捺): 差相等 */
    unordered_set<int> sumSet;  /* / 对角线(撇): 和相等 */
public:
	int totalNQueens(int n) {
        // 边界情况
        if (n <= 0) return res;
        dfs(0, n);
        return res;
    }
    void dfs(int row, int n) /* n: N皇后的N, 对应几行几列的棋盘 */
    {
        if (row == n)
        {
            res++;
            return;
        }
        // row 不能相等
        for (int i = 0; i < n; i++)
        {
            if (!colSet.count(i) && !diffSet.count(row - i) && !sumSet.count(row + i))
            {
                colSet.insert(i);
                diffSet.insert(row - i);
                sumSet.insert(row + i);
                dfs(row + 1, n);

                colSet.erase(i);
                diffSet.erase(row - i);
                sumSet.erase(row + i);
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    int n = 8;
    auto res = sol.totalNQueens(n);  // n = 8 时有92组解
    cout << res << "\n";  

    return 0;
}