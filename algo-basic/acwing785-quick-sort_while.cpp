/** acwing地址: https://www.acwing.com/problem/content/description/787/
 * 作者: 极客学长 
 * 时间: 2021-08-13 11:07:23
*/
#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1e6 + 10;  // 1e6表示 10^6, 使用 #define 的宏定义也行
int n;
int A[N];

void quickSort(int A[], int l, int r)
{
    if (l >= r) return;
    int x = A[(l+r)/2];  // 分界点取中间点比较保险, 因为有时会遇到最坏的情形(极度散乱, 熵最大时)~
    int i = l - 1, j = r + 1;  /* 每次交换完之后, 向中间一定1位 */
    // 双指针
    while (i < j)
    {
        // 不管三七二十一, 先移动1步再比较
        while (A[++i] < x);
        while (A[--j] > x);
        // 上面两行等价于:
        // i++;
        // while (A[i] < x) i++;
        // j--;
        // while (A[j] > x) j--;
        if (i < j) swap(A[i], A[j]);
    }
    // 递归处理左侧
    quickSort(A, l, j);
    // 递归处理右侧
    quickSort(A, j + 1, r);
}

int main()
{
    freopen("in785.txt", "r", stdin);   /* 重定向到从文件输入, 提交到 OJ 前本句需删除. 输入文件中隔开符号应该为空格, 不能有逗号或其他任意字符. */
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]); 
    
    quickSort(A, 0, n - 1);             // 用具体的 l 和 r 值调用 quickSort(A, l, r);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    return 0;
}