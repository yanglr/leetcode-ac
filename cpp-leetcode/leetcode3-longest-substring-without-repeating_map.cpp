#include <string>
#include <cmath>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length(), res = 0;
        unordered_map<char, int> dict;
        // 双指针i, j
        for (int j = 0, i = 0; j < n; j++)
        {
            if (dict.find(s[j]) != dict.end()) // 如果当前字符出现过，curStartIdx更新为该字符上一次出现的位置
            {
                i = max(dict[s[j]], i); 
            }
            res = max(res, j - i + 1);  // 使用贪心思想进行子串延伸，关键!
            dict[s[j]] = j + 1;         /* 如果当前字符没出现过，将其index记录在dict中。下标 +1 代表 i 要移动的下个位置。 */
        }
        return res;        
    }
};

// Test
int main()
{
    Solution sol;
    string str = "pwwkew";
    int res = sol.lengthOfLongestSubstring(str);
    cout << res << endl;

    return 0;
}