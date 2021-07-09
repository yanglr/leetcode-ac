#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        if (s.empty() || s == "" || t.empty() || t == "" || s.length() < t.length())
        {
            return "";
        }

        vector<int> gapMap(128, 0);
        for (char ch : t) // 先遍历字符串t来初始化gapMap
        {
            gapMap[ch]++;
        }

        int right = 0, left = 0, gapSum = t.size(), start = 0, minLen = INT_MAX;
        while (right < s.size())
        {
            char ch = s[right];
            if (gapMap[ch] > 0)
            {
                gapMap[ch]--;
                gapSum--;
            }
            else
                gapMap[ch]--; /* 如果该字符不是需要的，加到map中，每出现一次累记1个-1 */

            if (gapSum == 0)
            {
                while (left < right && gapMap[s[left]] < 0) /* 右移左边界, 依次扔掉当前的字符, gapMap中相应的值+1 */
                {
                    gapMap[s[left++]]++;
                }
                if (right - left + 1 < minLen) // 更新窗口长度
                {
                    minLen = right - left + 1;
                    start = left;
                }

                // 当while循环结束, 即字符在gapMap中的值当为0且左边界继续右移时
                gapMap[s[left++]]++;
                gapSum++;
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