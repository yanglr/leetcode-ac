# 91 算法（第5期）

[91 算法第5期网站](https://leetcode-solution.cn/91)。

91 算法是一个为期 91 天的大家一起打卡的活动, 大家可以一起做和学习带有讲解和按照专题的算法题。

## 主要编程语言
老师使用的语言主要是 Python/JavaScript...

本人暂定使用 C++ 来完成。

## LeetCode 题解

| 基础篇                      | 进阶篇                    | 专题篇                                  |
| --------------------------- | ------------------------- | --------------------------------------- |
| [数组/栈/队列](#数组栈队列) | [高频面试题](#高频面试题) | [二分法](#二分法)                       |
| [链表](#链表)               | [前缀树](#前缀树)         | [滑动窗口](#滑动窗口)                   |
| [树](#树)                   | [并查集](#并查集)         | [位运算](#位运算)                       |
| [哈希表](#哈希表)           | [跳表](#跳表)             | [搜索(BFS/DFS/回溯)](#搜索bfs-dfs-回溯) |
| [双指针](#双指针)           | [剪枝](#剪枝)             | [背包问题](#背包问题)                   |
| -                           | [字符串匹配](#字符串匹配) | [动态规划](#动态规划)                   |
| -                           | [堆](#堆)                 | [分治](#分治)                           |
| -                           | -                         | [贪心](#贪心)                           |

## 每日一题 汇总

-   [x] [【day1】989.数组形式的整数加法](./daily/posts/day1.md)
-   [x] [【day2】821.字符的最短距离](./daily/posts/day2.md)
-   [x] [【day3】1381.设计一个支持增量操作的栈 09-12](./daily/posts/day3.md)
-   [x] [【day4】394.字符串解码 09-13](./daily/posts/day4.md)
-   [x] [【day5】232.用栈实现队列 09-14](./daily/posts/day5.md)
-   [x] [【day6】768.最多能完成排序的块 II  09-15](./daily/posts/day6.md)
-   [x] [【day7】61.旋转链表](./daily/posts/day7.md)
-   [x] [【day8】24.两两交换链表中的节点](./daily/posts/day8.md)
-   [x] [【day9】109.有序链表转换二叉搜索树 09-18](./daily/posts/day9.md)
-   [x] [【day10】160.相交链表 09-19](./daily/posts/day10.md)
-   [x] [【day11】142.环形链表 II 09-20](./daily/posts/day11.md)
-   [x] [【day12】146.LRU 缓存机制 09-21](./daily/posts/day12.md)
-   [x] [【day13】104.二叉树的最大深度 09-22](./daily/posts/day13.md)
-   [x] [【day14】100.相同的树 09-23](./daily/posts/day14.md)
-   [x] [【day15】129.求根到叶子节点数字之和](./daily/posts/day15.md)
-   [x] [【day16】513.找树左下角的值 09-25](./daily/posts/day16.md)
-   [x] [【day17】297.二叉树的序列化与反序列化 09-26](./daily/posts/day17.md)
-   [x] [【day18】987.二叉树的垂序遍历 09-27](./daily/posts/day18.md)
-   [x] [【day19】1.两数之和 09-28](./daily/posts/day19.md)
-   [x] [【day20】347.前 K 个高频元素](./daily/posts/day20.md)
-   [x] [【day21】447.回旋镖的数量 09-30](./daily/posts/day21.md)
-   [x] [【day22】3.无重复字符的最长子串 10-01](./daily/posts/day22.md)
-   [x] [【day23】30.串联所有单词的子串10-02](./daily/posts/day23.md)
-   [x] [【day24】1590.使数组和能被P整除 10-03](./daily/posts/day24.md)
-   [x] [【day25】876.链表的中间结点 10-04](./daily/posts/day25.md)
-   [x] [【day26】26.删除有序数组中的重复项 10-05](./daily/posts/day26.md)
-   [x] [【day27】35.搜索插入位置 10-06](./daily/posts/day27.md)
-   [x] [【day28】239.滑动窗口最大值  10-07](./daily/posts/day28.md)
-   [x] [【day29】997.找到小镇的法官 10-08](./daily/posts/day29.md)
-   [x] [【day30】886.可能的二分法 10-09](./daily/posts/day30.md)
-   [x] [【day31】1203.项目管理 10-10](./daily/posts/day31.md)
-   [x] [【day32】657.机器人能否返回原点 10-11](./daily/posts/day32.md)


## 基础篇

### 数组，栈，队列

#### 每日一题

-   [x] [【day1】989.数组形式的整数加法](./daily/posts/day1.md)
-   [x] [【day2】821.字符的最短距离](./daily/posts/day2.md)
-   [x] [【day3】1381.设计一个支持增量操作的栈 09-12](./daily/posts/day3.md)
-   [x] [【day4】394.字符串解码 09-13](./daily/posts/day4.md)
-   [x] [【day5】232.用栈实现队列 09-14](./daily/posts/day5.md)
-   [x] [【day6】768.最多能完成排序的块 II  09-15](./daily/posts/day6.md)


#### 数组拓展题目

-   [x] [75.颜色分类](./daily/posts/basic/array-stack-queue/ext-sort-colors.md)


#### 栈拓展题目

-   [ ] [946. 验证栈序列](https://leetcode-cn.com/problems/validate-stack-sequences/)

#### 队列拓展题目

-   [ ] [155.最小栈](https://leetcode-cn.com/problems/min-stack/)


#### 相关专题

-   [ ] [前缀和](https://lucifer.ren/blog/2020/09/27/atMostK/)

### 链表

#### 每日一题

-   [x] [【day7】24.两两交换链表中的节点](./daily/posts/basic/linked-list/07.swap-nodes-in-pairs.md)


#### 链表拓展题目

-   [x] [2.两数相加](./daily/posts/problems/2.add-two-numbers.md)

### 树

#### 每日一题

-   [x] [【day-13】104.二叉树的最大深度](./daily/posts/basic/binary-tree/13.maximum-depth-of-binary-tree.md)

#### 树拓展题目

-   [x] [105.从前序与中序遍历序列构造二叉树](./daily/posts/basic/binary-tree/

### 哈希表

#### 每日一题

-   [x] [【day-19】1.两数之和](./daily/posts/basic/hashmap/19.two-sum.md)


#### 哈希表拓展题目

-   [x] [645.错误的集合](./daily/posts/basic/hashmap/ext-set-mismatch.md)


### 双指针

#### 每日一题

-   [x] [【day-25】35.搜索插入位置](./daily/posts/basic/two-pointers/25.search-insert-position.md)


#### 双指针拓展题目

-   [x] [875.爱吃香蕉的珂珂](./daily/posts/basic/two-pointers/ext-koko-eating-bananas.md)

## 进阶篇

### 高频面试题

**二叉树遍历系列**

-   [x] [【day-34】二叉树遍历系列](./daily/posts/medium/hot/34.traversal-of-binary-tree.md)

**反转链表系列**

-   [x] [【day-35】206.反转链表](./daily/posts/medium/hot/35.reverse-linked-list.md)

**位运算系列**

-   [ ] [【day-36】78.子集](./daily/posts/medium/hot/36.subsets.md)

**动态规划系列**

-   [x] [【day-37】62.不同路径](./daily/posts/medium/hot/37.unique-paths.md)


**有效括号系列**

-   [x] [【day-38】20.有效括号](./daily/posts/medium/hot/38.valid-parentheses.md)


**设计系列**

-   [ ] [【day-39】剑指 Offer09.用两个栈实现队列](./daily/posts/)


**前缀和系列**

-   [x] [【day-40】网易面试题](./daily/posts/medium/hot/40.netease.md)


### 前缀树

-   [x] [【day-41】208.实现 Trie](./daily/posts/medium/trie/41.implement-trie-prefix-tree.md)

### 并查集

#### 每日一题

-   [x] [【day-44】547.朋友圈](./daily/posts/medium/union-find/44.friend-circles.md)


#### 拓展

-   [x] [1202.交换字符串中的元素](./daily/posts/medium/union-find/ext-smallest-string-with-swaps.md)

### 跳表

-   [ ] [【day-47】1206.设计跳表](./daily/posts/)

### 剪枝

#### 每日一题

-   [x] [【day-48】814.二叉树剪枝](./daily/posts/medium/prune/48.binary-tree-pruning.md)


### 字符串匹配

#### 每日一题

-   [ ] [【day-52】28.实现 strStr()](./daily/posts/medium/rk-kpm/52.implement-strstr.md)

#### 拓展题目

-   [ ] [1371.每个元音包含偶数次的最长子字符串](./daily/posts/medium/day-52.md)


### 堆

#### 每日一题

-   [x] [【day-54】215.数组中的第 K 个最大元素](./daily/posts/medium/heap/54.kth-largest-element-in-an-array.md)


## 专题篇

### 二分法

#### 每日一题

-   [x] [【day-61】69.x 的平方根](./daily/posts/topics/binary-search/61.sqrtx.md)


#### 拓展题目

-   [x] [33.搜索旋转排序数组](./daily/posts/topics/binary-search/ext-search-in-rotated-sorted-array.md)

### 滑动窗口

#### 每日一题

-   [x] [【day-67】1456.定长子串中元音的最大数目](./daily/posts/topics/sliding-window/67.maximum-number-of-vowels-in-a-substring-of-given-length.md)

#### 拓展题目

-   [x] [581.最短无序连续子数组](./daily/posts/topics/sliding-window/ext-shortest-unsorted-continuous-subarray.md)

### 位运算

-   [ ] [【day-72】268.缺失数字](./daily/posts/topics/day-72.md)


### 搜索(BFS, DFS, 回溯)

-   [x] [【day-74】1254.统计封闭岛屿的数目](./daily/posts/topics/day-74.md)


-   [x] [5210.球会落何处](./daily/posts/topics/searching/ext-where-will-the-ball-fall.md)

### 背包问题

-   [x] [【day-80】322.零钱兑换](./daily/posts/topics/day-80.md)


### 动态规划

-   [ ] [【day-84】爬楼梯变种](./daily/posts/topics/day-84.md)


### 分治

-   [x] [【day-88】96.不同的二叉搜索树](./daily/posts/topics/day-88.md)


### 贪心

#### 每日一题

-   [ ] [【day-90】765.情侣牵手](./daily/posts/topics/day-90.md)

#### 贪心拓展题目

-   [x] [135.分发糖果](./daily/posts/topics/greedy/ext-candy.md)


## 其他

-   [x] [77.组合](./daily/posts/extensions/77.combination.md)


> [在线电子书](https://geekplayers.com/leetcode)

