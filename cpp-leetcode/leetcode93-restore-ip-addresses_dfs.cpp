#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, 0, "", "", res);
        return res;
    }
    /* seg: 当前扫描的两个.之间的部分, ip: 当前从index=0处开始拼接起来的字符串, 合法的segIndex: [0, 2] */
    void dfs(string s, int startPos, int segIndex, string seg, string ip, vector<string>& res)
    {
        if (startPos == s.size() && segIndex == 3 && isValidSeg(seg))
            res.push_back(ip + seg);
        else if (startPos < s.size() && segIndex <= 3)
        {
            char ch = s[startPos]; 
            /* 例如, 当输入字符串是"10203040"且恰好处理到其中的字符'2'时, 有可能得到"102.", 也可能得到"10.2" */
            if (isValidSeg(seg + ch)) /* 尝试往seg中添加原串s(只有数字, 不含有点.)中的一个新字符 */ 
                dfs(s, startPos + 1, segIndex, seg + ch, ip, res);
            if (seg != "" && segIndex < 3) /* 尝试往当前的ip串末尾加入一个点. */ 
                dfs(s, startPos, segIndex + 1, "", ip + seg + ".", res);
        }
    }

    bool isValidSeg(string seg)
    {
        return stoi(seg) <= 255 && (seg == "0" || seg[0] != '0');
    }
};

// Test
int main()
{
    Solution sol;
    string S = "25525511135";
    vector<string> res = sol.restoreIpAddresses(S);

    for (string str : res)
        cout << str << endl;
    
    return 0;
}