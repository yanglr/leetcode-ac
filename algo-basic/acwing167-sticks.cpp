#include <algorithm>
// #include <cstring>
#include <iostream>
using namespace std;

const int N = 70;
int n;            // 所有木棒的个数
int sum, length;  /* sum: 所有木棒的长度总和, length: 当前枚举的木棍的长度 */

int sticks[N];    // 存所有的木棒
bool st[N];       //  存每根木棒当前有没有被用过

/**
 * u: 当前拼到了第几根(1, 2…)木棍, 木棒内部的编号No.
   cur: 当前这根木棍已经拼了多长
   start: 当前从原木棒数组的哪个index开始枚举
*/
bool dfs(int u, int cur, int start)
{
    if (u * length == sum) // 找到了一组解
    {
        return true;
    }
    if (cur == length) /* 搜索下一个新的木棍 */
        return dfs(u + 1, 0, 0);
    for (int i = start; i < n; i++) // 循环需要从start开始
    {
        if (st[i]) continue; // 当前木棍用掉了
        int l = sticks[i];
        if (cur + l <= length)
        {
            st[i] = true;
            if (dfs(u, cur + l, i + 1))
            {
                return true;
            }
            st[i] = false; // 清空访问状态
            // 剪枝3 如果是第一根木棍放入失败, 则一定失败
            if (!cur)
            {
                return false;
            }
            //剪枝4 如果是最后一根木棒放入失败, 则一定失败
            if (cur + l == length)
            {
                return false;
            }
            // 剪枝2 如果失败了, 则跳过长度相等的木棒
            int j = i;
            while (j < n && sticks[j] == l)
            {
                j++;
            }
            i = j - 1;
        }
    }
    return false;
}

/**
    输入样例：

    9
    5 2 1 5 2 1 5 2 1
    4
    1 2 3 4
    0
*/
// Test
int main()
{
    while (cin >> n, n)
    {
        sum = 0, length = 0;
        fill(st, st + N, false); // 把所有长度>50的木棍的访问状态清空一下
        for (int i = 0; i < n; i++)
        {
            cin >> sticks[i];
            if (sticks[i] > 50)
            {
                continue;
            }
            sum += sticks[i];
            length = max(length, sticks[i]);
        }

        // 剪枝: 优化搜索顺序
        sort(sticks, sticks + n, greater<int>());
        for (int i = 0; i < n; i++)
        {
            if (sticks[i] > 50)
            {
                st[i] = true;
            }
        }

        while (true)
        {
            if (sum % length == 0 && dfs(0, 0, 0))
            {
                cout << length << endl;
                break;
            }
            length++;
        }
    }
    return 0;
}