#include<iostream>
#include<cstdio>
using namespace std;

const int N = 100010;
int n;
int A[N], tmp[N];

void mergeSort(int A[], int l, int r)
{
    if (l >= r) return;
    
    int mid = (l+r)/2;
    mergeSort(A, l, mid);
    mergeSort(A, mid+1, r);
    int i = l, j = mid+1, k=0;
    while (i <= mid && j <= r)
    {
        if (A[i] <= A[j]) tmp[k++] = A[i++];
        else tmp[k++] = A[j++];
    }
    // 上面这次循环结束时, 如果左半边没处理完需要进行如下操作
    while (i <= mid) tmp[k++] = A[i++];
    while (j <= r) tmp[k++] = A[j++];
    for (int i=l, j=0; i <= r; i++, j++) A[i] = tmp[j];
}

int main()
{
    // scanf("%d", &n);
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &A[i]);
    n = 5;
    int T[] = {3, 2, 2, 5, 3};
    copy(T, T + n, A);
    
    mergeSort(A, 0, n-1);
    
    for (int i = 0; i<n; i++) printf("%d ", A[i]);
    
    return 0;
}