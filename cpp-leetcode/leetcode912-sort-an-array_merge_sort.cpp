#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 2e5 + 10;
int A[N], tmp[N];   
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int len = nums.size();
        mergeSort(nums, 0, len - 1);
        return nums;
    }
    void mergeSort(vector<int>& A, int l, int r)
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
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {5, 1, 3, 1, 2, 3, 3};
    auto res = sol.sortArray(nums);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}