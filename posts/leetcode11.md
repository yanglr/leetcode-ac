# [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

### 英文题: Container with most water

<table>    <tr>     <td bgcolor=white>&nbsp; ● &nbsp;难度: </td>    <td bgcolor=#F0AD4E width=8.5%><font color=white>中等</font></td> <td bgcolor=white　width=79%></td>  </tr></table>



给你 `n` 个非负整数 `a1，a2，...，a``n`，每个数代表坐标中的一个点 `(i, ai)` 。在坐标内画 `n` 条垂直线，垂直线 `i` 的两个端点分别为 `(i, ai)` 和 `(i, 0)` 。找出其中的两条线，使得它们与 `x` 轴共同构成的容器可以容纳最多的水。

**说明：** 你不能倾斜容器。

 

**示例 1：**

![img](https://aliyun-lc-upload.oss-cn-hangzhou.aliyuncs.com/aliyun-lc-upload/uploads/2018/07/25/question_11.jpg)

```
输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
```

**示例 2：**

```
输入：height = [1,1]
输出：1
```

**示例 3：**

```
输入：height = [4,3,2,1,4]
输出：16
```

**示例 4：**

```
输入：height = [1,2,1]
输出：2
```

 

**提示：**

- `n = height.length`
- `2 <= n <= 3 * 104`
- `0 <= height[i] <= 3 * 104`



### 分析:

使用双指针(左右对撞型)，以打擂台的方式更新值。

面积 area =  首尾高度差x水平index之差 = `min(height[left], height[right]) * (right - left)`

<br/>

### 已AC的C++代码:

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len - 1;

        int maxArea = INT_MIN;        
        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            if(area > maxArea)
                maxArea = area;
            
            if(height[left] <= height[right])
                left++;
            else right--;
        }
        return maxArea;
    }
};
```



















