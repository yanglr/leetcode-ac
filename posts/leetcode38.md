# [38. 外观数列](https://leetcode-cn.com/problems/count-and-say/) (报数)

### 英文题目: Count and Say

<table>    <tr>     <td bgcolor=white>&nbsp; ● &nbsp;难度: </td>    <td bgcolor=#F0AD4E width=8.5%><font color=white>中等</font></td> <td bgcolor=white　width=79%></td>  </tr></table>

给定一个正整数 `n` ，输出外观数列的第 `n` 项。

「外观数列」是一个整数序列，从数字 1 开始，序列中的每一项都是对前一项的描述。

你可以将其视作是由递归公式定义的数字字符串序列：

- `countAndSay(1) = "1"`
- `countAndSay(n)` 是对 `countAndSay(n-1)` 的描述，然后转换成另一个数字字符串。



前五项如下：

```
1.     1
2.     11
3.     21
4.     1211
5.     111221
第一项是数字 1 
描述前一项，这个数是 1 即 “ 一 个 1 ”，记作 "11"
描述前一项，这个数是 11 即 “ 二 个 1 ” ，记作 "21"
描述前一项，这个数是 21 即 “ 一 个 2 + 一 个 1 ” ，记作 "1211"
描述前一项，这个数是 1211 即 “ 一 个 1 + 一 个 2 + 二 个 1 ” ，记作 "111221"
```

要 **描述** 一个数字字符串，首先要将字符串分割为 **最小** 数量的组，每个组都由连续的最多 **相同字符** 组成。然后对于每个组，先描述字符的数量，然后描述字符，形成一个描述组。要将描述转换为数字字符串，先将每组中的字符数量用数字替换，再将所有描述组连接起来。



例如，数字字符串 `"3322251"` 的描述如下图：

![count and say](https://pic.rmb.bdstatic.com/bjh/8514fdc080a7eb404f6edb5807428395.png)
 

**示例 1：**

```
输入：n = 1
输出："1"
解释：这是一个基本样例。
```

**示例 2：**

```
输入：n = 4
输出："1211"
解释：
countAndSay(1) = "1"
countAndSay(2) = 读 "1" = 一 个 1 = "11"
countAndSay(3) = 读 "11" = 二 个 1 = "21"
countAndSay(4) = 读 "21" = 一 个 2 + 一 个 1 = "12" + "11" = "1211"
```

 

**提示：**

- `1 <= n <= 30`


## 分析:

本题可使用递归或迭代来解决，下面的几种方法都使用了迭代。

<br/>

主体思路: 以已知a4=1211, 来求a5为例来说明如何用迭代法实现。
首先将不同字符间(用虚线)划开进行分片，即 1|2|11，分别统计各个分片中连续相同的字符数即可。


### 方法1

本题从f(1)到f(n)需要迭代 n-1 次来解决，每次迭代以上一次的迭代结果作为起点，将该迭代结果res中不同字符间(用虚线)划开进行分片，即 1|2|11。

当循环变量从0 -> n-1 且没到末尾的分片时, 每出现新的字符时，把已处理的连续相同字符的信息插入到结果字符串中。而到末尾分片时，需要单独把末尾连续相同字符的信息插入到结果字符串中，因为对末尾一段字符来说，不会再有新的字符了，该数据也需要写入。

#### 已AC的C++代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";    // f(1) = 1
        
        string res = "1";  // f(1) = 1, 作为迭代的初始值放入到结果中
        for(int i=0; i<n-1; i++)
        {
            string currentCombinedStr = "";
            char curFirstChar = res[0];    // 存放当前分片的第一个字符
            int currentCharCount = 0;            
            for(char ch : res)             // 将当前的字符与当前分片的第一个字符比较
            {
                if(ch == curFirstChar)
                    currentCharCount += 1;
                else {         
                    // 出现新的字符时，把已处理的连续相同字符的信息插入到结果字符串中
                    currentCombinedStr.append(to_string(currentCharCount));
                    currentCombinedStr.push_back(curFirstChar);

                    curFirstChar = ch;
                    currentCharCount = 1;
                }
            }

            // 把末尾连续相同字符的信息插入到结果字符串中(对末尾一段字符来说，不会再有新的字符了)
            currentCombinedStr.append(to_string(currentCharCount));
            currentCombinedStr.push_back(curFirstChar);            
            res = currentCombinedStr; // 将结果用作下一轮循环的初始值
        }

        return res;
    }
};
```


### 方法2

思路与方法1类似，只是将 `字符串中第一个连续相等数的数量`的功能封装成单独的函数，以便后面使用。

#### 已AC的C++代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string res = "1";  // f(1) = 1
        
        while (n > 1) {
            string curStr = "";
            for (int i = 0; i < res.size(); i++) {
                int count = getRepeatCount(res.substr(i));  // 截取从当前字符到末尾的子串
                curStr += to_string(count);
                curStr.push_back(res[i]);

                // 跳过重复的字符, 共处理一次即可
                i = i + count - 1;
            }
            n--;  // 总共需要迭代 n-1 次

            res = curStr;  // 将结果用作下一轮循环的初始值
        }
        return res;
    }

    /* 得到字符串 str 中第一个分片中连续相等数的重复个数，例如: "111221" 返回 3, "2" 返回 1 */
    int getRepeatCount(string str) {
        int count = 1;
        char same = str[0];
        for (int i = 1; i < str.size(); i++) {
            if (same == str[i]) {
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
```


### 方法3

懂了方法1 或 方法2后，也可以用下面的方式完成。

#### 已AC的C++代码

```cpp
class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";

        string res = "1";
        while (--n) {
            string curStr = "";
            for (int i = 0; i < res.size(); ++i) {
                int count = 1; // 出现第一个新字符, count置为1
                while (i + 1 < res.size() && res[i] == res[i + 1]) {  /* 这里与上1层循环用的是同一个i, 且区间是上层循环的子区间, 故时间复杂度是O(n^2) */
                    count++;
                    i++;
                }
                curStr += to_string(count) + res[i];
            }
            res = curStr;  // 将结果用作下一轮循环的初始值
        }
        return res;
    }
};
```

以上3种方法都是`迭代法`的实现，本题还可以使用递归来做，有兴趣的小伙伴可以试试~

<hr/>

本人公众号 [大白技术控](https://www.ershicimi.com/a/yOzq9w3e), 2万读者。

知乎 [Bravo Yeung](https://www.zhihu.com/people/legege007), 4.5万读者。

B站 [极客学长呀](https://space.bilibili.com/1443957), 后续会用视频的形式来带大家刷LeetCode题，欢迎点个关注，敬请期待~

<br/>

更多清晰易懂的代码 (C++/Java/C#/Python/Go) 的 LeetCode 题解，会在我的 github 仓库 <https://github.com/yanglr/AlgoSolutions>中持续更新, 欢迎小伙伴们 star/fork，如果有不错的解法也欢迎提PR。

<br/>

**ps:** 仓库的代码中可以直接拿来本地调试喔，框架已搭好，根据自己的需求调整 test case即可~
