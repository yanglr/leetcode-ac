#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int restCount = s1.size(); /* 维护一个固定长度的窗口, 长度= len(s1), restCount: 剩下的待匹配字符的数量 */
        vector<int> s1Freq(26); /* 模拟一个计数哈希表 */
        for (int i = 0; i < s1.size(); i++)
            s1Freq[s1[i] - 'a']++;
        vector<int> s2Freq(26); /* 模拟一个计数哈希表, s2Freq: 字符串s中处于滑动窗口内的字符的频次 */
        for (int i = 0; i < s2.size(); i++)
        {
            char c = s2[i];
            s2Freq[c - 'a']++;
            if (s2Freq[c - 'a'] <= s1Freq[c - 'a']) /* 匹配到了一个待匹配的字符 */
                restCount--;
            if (i >= s1.size()) /* 删除最前面的1个字符 */
            {
                char h = s2[i - s1.size()];
                s2Freq[h - 'a']--;
                if (s2Freq[h - 'a'] < s1Freq[h - 'a'])
                    restCount++;
            }
            // 字符都匹配完成, 表示是一个有效的字母异位词(anagram)
            if (restCount == 0) /* i - startPos + 1 = len(s1) => startPos = i - len(s1) + 1 */
                return true;
        }
        return false;
    }
};

// Test
// Test
int main()
{
    Solution sol;
    string s1 = "ab";
    string s2 = "eidbaooo";
    
    auto res = sol.checkInclusion(s2, s1);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}