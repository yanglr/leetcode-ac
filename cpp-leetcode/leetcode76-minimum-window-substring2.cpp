#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string minLenWindow(string s, string t)
	{
		if (s.empty() || s == "" || t.empty() || t == "" || s.length() < t.length())
		{
			return "";
		}
		//维护两个数组，记录已有字符串指定字符的出现次数，和目标字符串指定字符的出现次数
		//ASCII表总长128
		vector<int> need(128);
		vector<int> have(128);

		//将目标字符串指定字符的出现次数记录
		for (int i = 0; i < t.length(); i++)
		{
			need[t[i]]++;
		}

		//分别为左指针，右指针，最小长度(初始值为一定不可达到的长度)
		//已有字符串中目标字符串指定字符的出现总频次以及最小覆盖子串在原字符串中的起始位置
		int left = 0, right = 0, minLen = INT_MAX, count = 0, start = 0;
		while (right < s.length())
		{
			char rch = s[right];
			//说明该字符不被目标字符串需要，此时有两种情况
			// 1.循环刚开始，那么直接移动右指针即可，不需要做多余判断
			// 2.循环已经开始一段时间，此处又有两种情况
			//  2.1 上一次条件不满足，已有字符串指定字符出现次数不满足目标字符串指定字符出现次数，那么此时
			//      如果该字符还不被目标字符串需要，就不需要进行多余判断，右指针移动即可
			//  2.2 左指针已经移动完毕，那么此时就相当于循环刚开始，同理直接移动右指针
			if (need[rch] == 0)
			{
				right++;
				continue;
			}
			//当且仅当已有字符串目标字符出现的次数小于目标字符串字符的出现次数时，count才会+1
			//是为了后续能直接判断已有字符串是否已经包含了目标字符串的所有字符，不需要挨个比对字符出现的次数
			if (have[rch] < need[rch])
			{
				count++;
			}
			//已有字符串中目标字符出现的次数+1
			have[rch]++;
			//移动右指针
			right++;
			//当且仅当已有字符串已经包含了所有目标字符串的字符，且出现频次一定大于或等于指定频次
			while (count == t.length())
			{
				//挡窗口的长度比已有的最短值小时，更改最小值，并记录起始位置
				if (right - left < minLen)
				{
					minLen = right - left;
					start = left;
				}
				char lch = s[left];
				//如果左边即将要去掉的字符不被目标字符串需要，那么不需要多余判断，直接可以移动左指针
				if (need[lch] == 0)
				{
					left++;
					continue;
				}
				//如果左边即将要去掉的字符被目标字符串需要，且出现的频次正好等于指定频次，那么如果去掉了这个字符，
				//就不满足覆盖子串的条件，此时要破坏循环条件跳出循环，即控制目标字符串指定字符的出现总频次(count）-1
				if (have[lch] == need[lch])
				{
					count--;
				}
				//已有字符串中目标字符出现的次数-1
				have[lch]--;
				//移动左指针
				left++;
			}
		}
		
		//如果最小长度还为初始值，说明没有符合条件的子串
		if (minLen == INT_MAX)
		{
			return "";
		}
		//返回的为以记录的起始位置为起点，记录的最短长度为距离的指定字符串中截取的子串
		return s.substr(start, minLen);
	}
};

// Test
int main()
{
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    auto res = sol.minLenWindow(s, t);
    cout << res << endl;

    return 0;
}