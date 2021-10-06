#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res; /* 存放这些子串的起始索引startPos */
        int restCount = p.size(); /* 维护一个固定长度的窗口, 窗口长度 = len(p), restCount: 剩下的待匹配字符的数量 */
        vector<int> pFreq(26); /* 模拟一个计数哈希表 */
        for (int i = 0; i < p.size(); i++)
            pFreq[p[i] - 'a']++;
        vector<int> sFreq(26); /* 模拟一个计数哈希表, sFreq: 字符串s中处于滑动窗口内的字符的频次 */
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            sFreq[c - 'a']++; /* 向窗口末尾加入1个新字符 */
            if (sFreq[c - 'a'] <= pFreq[c - 'a']) /* 当前窗口中这个字符的数量还没到上限, 可以成功加入 */
                restCount--;
            if (i >= p.size()) /* 删除原窗口最前面的那1个字符, 最新的startPos = i - len(p) + 1, 那么上一次的startPos = i - p.size() */
            {
                char h = s[i - p.size()]; /* h: 上一轮中窗口中最前面的字符 */
                sFreq[h - 'a']--;
                if (sFreq[h - 'a'] < pFreq[h - 'a'])
                    restCount++;
            }
            // 字符都匹配完成, 表示是一个有效的字母异位词(anagram)
            if (restCount == 0) /* i - startPos + 1 = len(p) => startPos = i - len(p) + 1 */
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string p = "ab";
    string s = "eidbaooo";
    
    auto res = sol.findAnagrams(s, p);
    for (auto& num : res)
        cout << num << " ";   

    return 0;
}