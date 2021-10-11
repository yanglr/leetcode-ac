# day2 - 821. 字符的最短距离[2021-09-11]

## 题目地址(821. 字符的最短距离)

https://leetcode-cn.com/problems/shortest-distance-to-a-character



## 思路

**题意**: 计算 `abs[i] = indexGap(i, 最近的字符c)`, 1 <= s.length <= 10^4
输出 `abs[i]`的数组

### 解法: 双指针 中心扩展

使用一个结果数组 gaps[]

将string s转为字符数组，然后从前往后遍历。
循环变量记作i, 对于每一趟:
如果当前字符就是要搜索的字符c, 距离记为 0，否则分别向左、向右找最近的字符c。
向左找, 找到第一个字符c, 将指针i与之的index之差记作leftDistance。
向右找, 找到第一个字符c, 将指针i与之的index之差记作rightDistance。
取两者的较小值。

依次填充 gaps[i] 的值即可。



## 代码

### 实现语言: C++

```cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> gaps(s.size());
        vector<char> chars(s.begin(), s.end());

        for (int i = 0; i < chars.size(); i++)
        {
            // 如果当前字符就是要搜索的字符c, 距离为 0
            if (chars[i] == c) gaps[i] = 0;
            else /* 否则分别向左、向右找最近的字符c */
            {
                int leftDistance = INT_MAX, rightDistance = INT_MAX;
                for (int left = i; left >= 0; left--)
                {
                    if (chars[left] == c) // 向左找, 找到第一个
                    {
                        leftDistance = i - left;
                        break;
                    }
                }
                for (int right = i; right < chars.size(); right++) // 向右找, 找到第一个
                {
                    if (chars[right] == c)
                    {
                        rightDistance = right - i;
                        break;
                    }
                }
                gaps[i] = min(leftDistance, rightDistance);
            }
        }

        return gaps;
    }
};
```

代码已同步上传到: [leetcode-ac/91algo - github.com](https://github.com/yanglr/leetcode-ac/tree/master/91algo)



#### 复杂度分析

- 时间复杂度：O(n^2)，其中 n 为字符串长度。
- 空间复杂度：O(n)



### 暴力解法:

可以过，但比较慢。

```cpp
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        // 题意: 计算 abs[i] = indexGap(i, nearest_c), 1 <= s.length <= 10^4
        // 输出 abs[i]的数组
        vector<int> indexes;  // indexes of char c
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c) indexes.push_back(i);
        }
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> gaps;  // gap for char s[i] to char c
            for (auto index : indexes)
                gaps.push_back(abs(index - i));
            auto it = min_element(gaps.begin(), gaps.end());
            res.push_back(*it);
        }
        return res;
    }
};
```
