### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

<table>    <tr>     <td bgcolor=white>&nbsp; ● &nbsp;难度: </td>    <td bgcolor=#5cb85c width=8.5%><font color=white>简单</font></td> <td bgcolor=white　width=79%></td>  </tr></table>



给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出 **和为目标值** *`target`* 的那 **两个** 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

<br/>

**示例 1：**

```
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
```

**示例 2：**

```
输入：nums = [3,2,4], target = 6
输出：[1,2]
```

**示例 3：**

```
输入：nums = [3,3], target = 6
输出：[0,1]
```

 

**提示：**

- `2 <= nums.length <= 104`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **只会存在一个有效答案**

**进阶：** 你可以想出一个时间复杂度小于 O(n<sup>2</sup>) 的算法吗？

<br/>

### 英文题目: 2 sum (Two sum)

Given an array of integers `nums` and an integer `target`, return _indices of the two numbers such that they add up to `target`.
You may assume that each input would have **_exactly_ one solution**, and you may not use the _same_ element twice.
You can return the answer in any order.

<br/>

**Example 1:**

**Input:** nums = [2,7,11,15], target = 9
**Output:** [0,1]

**Explaination:** Because nums[0] + nums[1] == 9, we return [0, 1].


**Example 2:**
**Input:** nums = [3,2,4], target = 6
**Output:** [1,2]


**Example 3:**
**Input:** nums = [3,3], target = 6
**Output:** [0,1]


 
**Constraints:**

- `2 <= nums.length <= 103`
- `-109 <= nums[i] <= 109`
- `-109 <= target <= 109`
- **Only one valid answer exists.**



### 分析:

**方法1**: 暴力法，复杂度O(n^2)，会TLE(超时).

**方法2**: 双指针法, 固定一个, 找另一个. 发现第一次出现`nums[i] + nums[j] == target`就返回结果.

**方法3**: hashmap查表，在表中找 target - 当前循环变量i对应的那个数。用一个哈希表(C++中用unordered_map, C#中用dictionary, Python中用dict，Java中可以直接用HashMap)，存储每个数对应的下标，复杂度O(n);

**方法4**: 快排 + 双指针

<br/>

### 方法2 AC代码:

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        vector<int> res(2);
        // 双指针, 先固定一个
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
};
```


### 方法3 AC代码:
​
```cpp
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

### 方法3的另一种写法:

```cpp
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
​

### 方法4 AC代码:

- 定义一个struct, 存储 index 和 value
- 使用两个指针, l 和 r, l++, r--

left自增, right 自减


**注意**: 如果要在一个struct上调用STL中的sort方法，需要先为其定义好 compare 函数。
​

具体代码如下:
```cpp
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
