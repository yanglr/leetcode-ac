#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastIndexDict(128, 0); /* 将小写字母的ASCII码作为key, value是最后一次出现的pos */
        const int len = 0;
        for (int i = 0; i < len; i++)
            lastIndexDict[s[i]] = i;
        vector<int> res;
        int start = 0; // 用区间[start, end]表示一个片段(label)
        int end = 0;              
        for (int i = 0; i < len; i++) /* 从前往后扫描字符, 看当前区间是否需要扩展 */
        {
            int curChLastIndex = lastIndexDict[s[i]];
            end = max(end, curChLastIndex);
            if (i == end)
            {
                int curLen = end - start + 1;
                res.push_back(curLen);
                start = end + 1;
            }            
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "ababcbacadefegdehijhklij";
    auto res = sol.partitionLabels(s);           
    for (auto &num : res)
        cout << num << endl;
    return 0;
}