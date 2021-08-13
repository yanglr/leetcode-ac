/** acwing地址: https://www.acwing.com/problem/content/description/787/
 * 作者: 极客学长
 * 日期: 2021-08-13 11:27:23
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e6 + 10;  // 1e6表示 10^6
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
        i++;
        while (A[i] < x) i++;
        j--;
        while (A[j] > x) j--;
        if (i < j) swap(A[i], A[j]);
    }
    // 递归处理左侧
    quickSort(A, l, j);
    // 递归处理右侧
    quickSort(A, j+1, r);
}

int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &A[i]);
    n = 5;
    int T[] = {10, 7, 6, 2, 4};
    copy(T, T + 5, A);          // std::copy
    
    quickSort(A, 0, n - 1);     // 用具体的 l 和 r 值调用 quickSort(A, l, r);
    
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
    
    return 0;
}