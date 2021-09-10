#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cIndexes; // 存放字符c在原数组中的下标索引
        int n = s.size();
        vector<int> res(n);

        for (int i = 0; i < n; i++)
            if (s[i] == c) cIndexes.push_back(i);
        
        int len = cIndexes.size();
        int left = 0, right = 0; /* 双指针left, right, left: 从左向右扫描原数组时的下标, right: 数组cIndexes中字符c的下标 */
        for (int i = 0; i < n; i++)
        {
            /* 用 [left, right] 记录要搜索的范围, 最开始的搜索范围是[0, 字符c的第1个索引], 确保该范围内只有1个字符c。
               当 i 恰好扫描完当前这个区间时, 更新left 和 right, 扫描下一个区间[字符c的第1个索引+1, 字符c的第2个索引]。
               依此类推~
            */
            if (i > cIndexes[right])
            {
                left = right;
                if (right < len - 1) right++;
            }
            res[i] = min(abs(cIndexes[right] - i), abs(cIndexes[left] - i));
        }

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "loveleetcode";
    char c = 'e';
    auto res = sol.shortestToChar(s, c);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}