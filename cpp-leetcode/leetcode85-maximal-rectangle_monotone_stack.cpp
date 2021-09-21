#include<vector>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> row(n, 0);
        /* 以下循环是为了计算出目标矩阵的下界, 每次把row[j]更新为第0 ~ i-1行第j列压缩后得到的新值(row相当于
        leetcode84输入的heights数组), 如果出现连续1就累加, 否则表示无法形成柱子(悬空了)就直接清零. */
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1') row[j] += 1;
                else row[j] = 0;
            }
            int curArea = largestRecArea(row); /* 对于压缩后得到的二维数组中的当前行 row, 可以直接使用leetcode84的解法 */
            res = max(res, curArea);
        }
        return res;
    }
    int largestRecArea(vector<int> row)
    {
        row.insert(row.begin(), 0); /* 在数组首尾都加零, 前者避免 i - stack.top() - 1 时遇到栈空，后者保证恰好能进行一次退栈。 */
        row.push_back(0);
        stack<int> st;     /* 栈中存放当前数在原矩阵中的水平方向的index */
        st.push(0);
        int area = 0;
        for (int i = 1; i < row.size(); i++)
        {
            if (row[i] > row[st.top()]) st.push(i);
            else
            {
                while (row[st.top()] > row[i])
                {
                    int H = row[st.top()];
                    st.pop();
                    int W = i - st.top() - 1;
                    area = max(area, H * W);
                }
                st.push(i);
            }
        }
        return area;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<char>> matrix
    {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    auto res = sol.maximalRectangle(matrix);
    cout << res << endl;

    return 0;
}