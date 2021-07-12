#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;         
        double res;
        int m = nums1.size();
        int n = nums2.size();
        int len;

        int i = 0, j = 0;
        while (i < m && j < n)  // 只要一个指针扫到数组末尾，循环结束
        {
            if(nums1[i] <= nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }

        while(i < m)  // 数组nums1没跑完，nums2已跑完时
        {
            nums.push_back(nums1[i]);
            i++;
        }

        while(j < n)  // 数组nums2没跑完，nums1已跑完时
        {
            nums.push_back(nums2[j]);
            j++;
        }
        len = nums.size();
        if(len % 2 == 0)
        {
            res = (nums[len/2] + nums[len/2-1])/2.0;
        }
        else res = nums[len/2];

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {0,2,5};
    double res = sol.findMedianSortedArrays(nums1, nums2);
    cout << res << endl;

    return 0;
}