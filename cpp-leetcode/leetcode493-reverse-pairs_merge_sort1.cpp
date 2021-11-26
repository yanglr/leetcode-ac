#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        int res = 0;
        vector<int> temp(size);
        mergesort(nums, temp, left, right, res);
        return res;
    }
    void mergesort(vector<int>& nums, vector<int>& temp, int left, int right, int& res)
    {
        if (left >= right) return;                  // base case: 只剩一个元素就是有序的了
        int mid = left + (right - left) / 2;
        
        mergesort(nums, temp, left, mid, res);      //对左区间排序
        mergesort(nums, temp, mid + 1, right, res); //对右区间排序
        int i = left;
        int j = mid + 1;
        while (i <= mid && j <= right) // 左右区间都是有序的了，进行统计操作
        {
            if ((long long)nums[i] > 2 * (long long)nums[j]) // *2 会超 int 范围
            {
                res += (mid - i + 1); // 反转对个数
                j++;
            }
            else i++;
        }

        i = left;
        j = mid + 1;
        int p = 0;
        while (i <= mid && j <= right) // 进行归并操作
        {
            if (nums[i] > nums[j])
                temp[p++] = nums[j++];
            else
                temp[p++] = nums[i++];
        }
        while (i <= mid) //将左边剩余元素填充进temp中
            temp[p++] = nums[i++];
        while (j <= right) //将右序列剩余元素填充进temp中
            temp[p++] = nums[j++];
        p = 0;
        while (left <= right) //将temp中的元素全部拷贝到原数组[left,right]中
            nums[left++] = temp[p++];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.reversePairs(nums);
    cout << res << endl;

    return 0;
}