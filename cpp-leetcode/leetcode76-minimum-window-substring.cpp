#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        vector<int> map(128, 0);
        int remain = 0;
        for (char ch : t)
            map[ch]++; // map数组存着字符串 t 中各字母的数量。

        remain = t.length();
        int left = 0, right = 0, start = 0, minLen = INT_MAX;
        while (right < s.length())
        {
            char rch = s[right];
            if (map[rch] > 0)
                remain--;
            map[rch]--;       //先把右边的字符加入窗口
            if (remain == 0) //窗口中已经包含所需的全部字符
            {
                while (left < right && map[s[left]] < 0) //缩减窗口
                {
                    map[s[left++]]++;
                }                     //此时窗口符合要求
                if (right - left + 1 < minLen) //更新信息
                {
                    minLen = right - left + 1;
                    start = left;
                }
                map[s[left]]++; //左边界右移之前需要释放map[s[left]]
                left++;
                remain++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

// Test
int main()
{
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    auto res = sol.minWindow(s, t);
    cout << res << endl;

    return 0;
}