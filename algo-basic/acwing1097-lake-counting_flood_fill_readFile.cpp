/** 池塘计数 poj地址: http://poj.org/problem?id=2386 (提交时需要选G++, 而不是C++)
 * 作者: 极客学长 
 * 时间: 2021-08-22 21:55:16
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define x first         // 简化代码
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1010, M = N * N;

int n, m;
char g[N][N];
bool st[N][N];  // st: 代表state
PII q[M];

void bfs(int startX, int startY)
{
    int hh = 0, tt = -1;   // 模拟一个队列, hh: 队头, tt: 队尾, q中装的是pair<startX, startY>
    q[++tt] = {startX, startY};
    st[startX][startY] = true;

    while (hh <= tt)
    {
        PII t = q[hh++];

        for (int i = t.x - 1; i <= t.x + 1; ++i) // 遍历8个方向, 即遍历3*3的矩阵, skip掉最中间那个
        {
            for (int j = t.y - 1; j <= t.y + 1; ++j)
            {
                if (i == t.x && j == t.y)  // 不处理3x3个格子中最中间那个
                    continue;
                if (i < 0 || i >= n || j < 0 || j >= m)  // 越界的不处理
                    continue;
                if (g[i][j] == '.' || st[i][j])  // 当前位置是空地或当前位置之前已访问过, 不处理
                    continue;

                q[++tt] = {i, j};
                st[i][j] = true;
            }
        }
    }
}

int main()
{
    freopen("in1097.txt", "r", stdin);   /* 重定向到从文件输入, 提交到 OJ 前本句需删除. */
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", g[i]);

    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (g[i][j] == 'W' && !st[i][j])
            {
                bfs(i, j);
                cnt++;
            }
        }
    }

    printf("%d\n", cnt);
    return 0;
}