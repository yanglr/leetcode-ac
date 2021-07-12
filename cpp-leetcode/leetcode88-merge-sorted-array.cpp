#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res;  /* 题意: len(nums1) = m + n */
        int i = 0, j = 0;
        while (i < m && j < n)  // 只要一个指针扫到数组末尾，循环结束
        {
            if(nums1[i] <= nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m)  // 数组nums1没跑完，nums2已跑完时
        {
            res.push_back(nums1[i]);
            i++;
        }

        while(j < n)  // 数组nums2没跑完，nums1已跑完时
        {
            res.push_back(nums2[j]);
            j++;
        }     

        // 无需 return, 但需要更新nums1
        nums1 = res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {0,2,5};
    int m = 3, n = 3;
    sol.merge(nums1, m, nums2, n);

    for(auto num : nums1)
        cout << num << endl;

    return 0;
}