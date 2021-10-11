# day1 - leetcode989. 数组形式的整数加法[2021-09-10]

## 题目地址(989. 数组形式的整数加法)

[989. 数组形式的整数加法](https://leetcode-cn.com/problems/add-to-array-form-of-integer/)

https://leetcode-cn.com/problems/add-to-array-form-of-integer/

## 入选理由

1. 简单题目，适合大家上手。
2. 之前力扣官方的每日一题，质量比较高

## 题目描述

对于非负整数 `X` 而言，`*X*` 的*数组形式*是每位数字按从左到右的顺序形成的数组。例如，如果 `X = 1231`，那么其数组形式为 `[1,2,3,1]`。

给定非负整数 `X` 的数组形式 `A`，返回整数 `X+K` 的数组形式。

**示例 1：**

输入：A = [1,2,0,0], K = 34 输出：[1,2,3,4] 解释：1200 + 34 = 1234

**示例 2：**

输入：A = [2,7,4], K = 181 输出：[4,5,5] 解释：274 + 181 = 455

**示例 3：**

输入：A = [2,1,5], K = 806 输出：[1,0,2,1] 解释：215 + 806 = 1021

**示例 4：**

输入：A = [9,9,9,9,9,9,9,9,9,9], K = 1 输出：[1,0,0,0,0,0,0,0,0,0,0] 解释：9999999999 + 1 = 10000000000

**提示：**

1. `1 <= A.length <= 10000`
2. `0 <= A[i] <= 9`
3. `0 <= K <= 10000`
4. 如果 `A.length > 1`，那么 `A[0] != 0`

## 难度

- 简单

## 标签

[数组](https://leetcode-cn.com/tag/array/), [数学](https://leetcode-cn.com/tag/math/)

## 前置知识

- 数组的遍历

## 思路

### 双指针 + 进位加法逻辑

双指针, 让两个数的末位对齐, 两个指针 i, j均从各自字符串的末尾开始走。

定义一个数组来存放结果, 一个int值carry来记录每位的进位值, 初始值设为0。
算当前位置的数时, sum = a[i] + b[j] + carry, 每趟都要记得更新carry的值。

循环结束时, 由于低位的数字字符先加到了结果字符串中, 最后还需要 reverse 一次, 让位置恢复正常。

## 代码

### 实现语言: C++

```cpp
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int k) {
        if (k == 0) return A;
        vector<int> res;
        int n = A.size();
        // 对位相加
        int carry = 0;
        int sum = 0;
        int i = n - 1;
        while (k > 0 || i >= 0)
        {
            sum = carry + (k % 10);
            if (i >= 0) // 保证访问A[i]前不越界
                sum += A[i];

            carry = (sum <= 9) ? 0 : 1;
            res.push_back(sum % 10);
            k = k / 10;

            i--;
        }
        if (carry == 1) res.push_back(1);
        reverse(res.begin(), res.end());
        return res;
    }
};
```

代码已上传到: [leetcode-ac/91algo - github.com](https://github.com/yanglr/leetcode-ac/tree/master/91algo)

## 复杂度分析

- 时间复杂度：O(max(n, k))，其中 n 为数组长度, k为数K的长度。
- 空间复杂度：O(n), 主要是结果数组用的空间
