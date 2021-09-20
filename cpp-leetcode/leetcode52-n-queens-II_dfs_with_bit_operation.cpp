#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int count;
    int N;
public:
    int totalNQueens(int n)
    {
        count = 0;
        N = n;
        dfs(0, 0, 0, 0);
        return count;
    }
    /* row: rowSet
     * set1: / 对角线(撇): x与y的和相等
     * set2: \ 对角线(捺): x与y的差相等 */
    void dfs(int dep, int row, int set1, int set2)
    {
        if (dep == N)
        {
            count++;
            return;
        }
        for (int i = 0; i < N; i++) /* i代表列索引colIndex */
        {
            int j = 1 << i; /* 二进制100...0 (共i个0) */
            if ((j & row) || (j & set1) || (j & set2))  /* j & row: 水平方向上一个位置上重复放第2个皇后Q, (j & set1): / 斜对角线(撇)上, (j & set2): \ 斜对角线(捺)上  */
                continue;
            dfs(dep + 1, (j | row), (j | set1) << 1, (j | set2) >> 1);
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