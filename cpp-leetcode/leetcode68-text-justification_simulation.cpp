#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n = words.size();
        int p = 0;
        while (p < n)
        {
            int j = p + 1;
            int curLen = words[p].size();
            // check 每一行, 如果这些单词形成的串长度超过maxWidth, 直接 break, 否则继续添加
            while (j < n)
            {
                int totalLen = curLen + 1 + words[j].size(); // 相邻两个单词至少要保证有1个空格
                if (totalLen > maxWidth) break;                 
                curLen = totalLen; // 否则更新 curLen 并 check 下一个
                j++;
            }            
            if (j == p + 1) // 当前行只有一个单词时, 左对齐并补全空格
            {
                string word = words[p];
                if (maxWidth > curLen)
                    word += fillSpaces(maxWidth - curLen);
                res.push_back(word);
            }
            else
            {
                res.push_back("");
                string lastLine = res.back();                
                int remainSpCount = maxWidth - curLen; // remainSpCount：最后一处填充空格数
                int partsCount = j - 1 - p; /* partsCount: 单词之间能填充连续空格的位置个数（单词数 - 1） */
                // 如果是最后一行, 左对齐, 且单词之间只能填充一个空格, 末尾填充剩余空格数
                if (j == n)
                {
                    for (int i = 0; i <= partsCount; i++)
                    {
                        lastLine.append(words[p + i]);
                        if (i < partsCount) lastLine.push_back(' ');
                    }
                    lastLine.append(fillSpaces(remainSpCount));
                }
                else
                {   // 非最后一行且有多个单词, aveSpCount: 单词之间平均填充空格数
                    int aveSpCount = remainSpCount / partsCount;
                    remainSpCount -= aveSpCount * partsCount;
                    for (int i = 0; i <= partsCount; i++)
                    {
                        lastLine.append(words[p + i]);
                        if (i < remainSpCount) lastLine.append(fillSpaces(aveSpCount + 2));
                        else if (i < partsCount) lastLine.append(fillSpaces(aveSpCount + 1));
                    }
                }
                res.back() = lastLine;
            }
            p = j;
        }
        return res;
    }
    string fillSpaces(int n)
    {
        string str = "";
        for (int i = 0; i < n; i++)
            str.push_back(' ');
        return str;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    auto res = sol.fullJustify(words, maxWidth);
    for (auto num : res)
        cout << num << endl;
    
    return 0;
}