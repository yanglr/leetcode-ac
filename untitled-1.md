# leetcode1 两数之和【简单难度】

## [\#]() [1. 两数之和 \(opens new window\)](https://leetcode-cn.com/problems/two-sum/) <a id="_1-&#x4E24;&#x6570;&#x4E4B;&#x548C;"></a>

给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** _`target`_ 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

**示例 1：**

```text
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

1  
2  
3  


**示例 2：**

```text
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

1  
2  


**示例 3：**

```text
输入：nums = [3,3], target = 6
输出：[0,1]
```

1  
2  


**提示：**

* `2 <= nums.length <= 104`
* `-109 <= nums[i] <= 109`
* `-109 <= target <= 109`
* **只会存在一个有效答案**

**进阶：** 你可以想出一个时间复杂度小于 O\(n2\) 的算法吗？  


## [\#]() 英文题目: 2 sum \(Two sum\) <a id="&#x82F1;&#x6587;&#x9898;&#x76EE;-2-sum-two-sum"></a>

Given an array of integers `nums` and an integer `target`, return \_indices of the two numbers such that they add up to `target`. You may assume that each input would have _**exactly**_ **one solution**, and you may not use the _same_ element twice. You can return the answer in any order.

**Example 1:**

**Input:** nums = \[2,7,11,15\], target = 9 **Output:** \[0,1\]

**Explaination:** Because nums\[0\] + nums\[1\] == 9, we return \[0, 1\].

**Example 2:** **Input:** nums = \[3,2,4\], target = 6 **Output:** \[1,2\]

**Example 3:** **Input:** nums = \[3,3\], target = 6 **Output:** \[0,1\]

**Constraints:**

* `2 <= nums.length <= 103`
* `-109 <= nums[i] <= 109`
* `-109 <= target <= 109`
* **Only one valid answer exists.**

## [\#]() 分析: <a id="&#x5206;&#x6790;"></a>

**方法1**: 暴力法，复杂度O\(n^2\)，会TLE\(超时\);

**方法2**: hashmap查表，在表中找 target - 当前循环变量i对应的那个数。用一个哈希表\(C++中用unordered\_map, C\#中用dictionary, Python中用dict，Java中可以直接用HashMap\)，存储每个数对应的下标，复杂度O\(n\);

**方法3**: 快排 + 双指针 ​

## [\#]() 方法2 AC代码: <a id="&#x65B9;&#x6CD5;2-ac&#x4EE3;&#x7801;"></a>

​

```text
class Solution {
	public:
		vector<int> twoSum(vector<int> &nums, int target)
		{
			unordered_map<int, int> dict;
			vector<int> result;
			for(int i = 0; i < nums.size(); i++) {
				dict[nums[i]] = i; // 顺序的map映射: value->index 
			}
			for(int i = 0; i < nums.size(); i++)
			{
				int query = target - nums[i];
				if(dict.find(query) != dict.end() && dict[query] > i)  // dict[query] > i是为了防止重复计算 
				{
					result.push_back(i);
					result.push_back(dict[query]);
					break;
				}
			}
			return result;
		}
};
```

1  
2  
3  
4  
5  
6  
7  
8  
9  
10  
11  
12  
13  
14  
15  
16  
17  
18  
19  
20  
21  
22  


## [\#]() 方法2的另一种写法: <a id="&#x65B9;&#x6CD5;2&#x7684;&#x53E6;&#x4E00;&#x79CD;&#x5199;&#x6CD5;"></a>

```text
class Solution {
public:
	vector<int> twoSum(vector<int> &nums, int target)
	{
		unordered_map<int, int> dict;
		vector<int> res(2,-1), emptyVect;
		for(int i=0;i<nums.size();i++)
		{
			int query=target-nums[i];
			if(dict.find(query)==dict.end()) dict[nums[i]]=i;     // 逆序的map映射: value->index
			else {
				res[1]=i;
				res[0]=dict[query];
				return res;	
			}
		}
		return emptyVect;
	}
};
```

1  
2  
3  
4  
5  
6  
7  
8  
9  
10  
11  
12  
13  
14  
15  
16  
17  
18  
19  


​

## [\#]() 方法3 AC代码: <a id="&#x65B9;&#x6CD5;3-ac&#x4EE3;&#x7801;"></a>

* 定义一个struct, 存储 index 和 value
* 使用两个指针, l 和 r, l++, r--

left自增, right 自减

**注意**: 如果要在一个struct上调用STL中的sort方法，需要先为其定义好 compare 函数。 ​

具体代码如下:

```text
typedef struct node{
    int index;
    int value;
    node(){};
    node(int i, int v) : index(i), value(v){}
} Node;
 
bool compare(const Node& a, const Node& b){
    return a.value < b.value;
}
 
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
         
        int len = nums.size();
        assert(len >= 2);         
         
        vector<int> ret(2, 0);  // 初始化：ret包含2个值为0的元素
         
        vector<Node> nums2(len);
        for(int i = 0; i < len; i++){
            nums2[i] = Node(i+1, nums[i]);
        }
        
        sort(nums2.begin(), nums2.end(), compare);  // 在定义的struct上调用快排，T(n)=O(n*log(n))
         
        int l = 0;
        int r = len - 1;
        while(l < r){
            int sum = nums2[l].value + nums2[r].value;
            if(sum == target){
                ret[0] = min(nums2[l].index, nums2[r].index)-1;     // 注意，这里需要减去1
                ret[1] = max(nums2[l].index, nums2[r].index)-1;
                break;
            } else if(sum < target){
                l++;
            } else {
                r--;
            }
        }       
        return ret;  // 用两个指针来扫
    }
};
```

1  
2  
3  
4  
5  
6  
7  
8  
9  
10  
11  
12  
13  
14  
15  
16  
17  
18  
19  
20  
21  
22  
23  
24  
25  
26  
27  
28  
29  
30  
31  
32  
33  
34  
35  
36  
37  
38  
39  
40  
41  
42  
43  
44  


