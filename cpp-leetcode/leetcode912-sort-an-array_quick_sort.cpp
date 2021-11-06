#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 2e5 + 10;   
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        const int len = nums.size();
        quickSort(nums, 0, len - 1);
        return nums;
    }
    void quickSort(vector<int>& A, int l, int r)
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