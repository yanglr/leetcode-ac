### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

### 英文题目: Median of two sorted arrays

<table>    <tr>     <td bgcolor=white>&nbsp; ● &nbsp;难度: </td>    <td bgcolor=#D9534F width=8.5%><font color=white>困难</font></td> <td bgcolor=white　width=79%></td>  </tr></table>

给定两个大小分别为 `m` 和 `n` 的正序（从小到大）数组 `nums1` 和 `nums2`。请你找出并返回这两个正序数组的 **中位数** 。

 

**示例 1：**

```
输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
```

**示例 2：**

```
输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
```

**示例 3：**

```
输入：nums1 = [0,0], nums2 = [0,0]
输出：0.00000
```

**示例 4：**

```
输入：nums1 = [], nums2 = [1]
输出：1.00000
```

**示例 5：**

```
输入：nums1 = [2], nums2 = []
输出：2.00000
```

 

**提示：**

- `nums1.length == m`
- `nums2.length == n`
- `0 <= m <= 1000`
- `0 <= n <= 1000`
- `1 <= m + n <= 2000`
- `-106 <= nums1[i], nums2[i] <= 106`


**进阶：**你能设计一个时间复杂度为 `O(log (m+n))` 的算法解决此问题吗？

<br/>

### 思路
先合并两个有序数组，然后根据数组长度的奇偶来取到中位数。如果是偶数个，就取中间两个的平均数；如果是奇数个，直接取最中间的即可。

与 `leetcode 88. 合并两个有序数组` 类似。

<br/>


### 已AC的C++代码:
```cpp
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
```

