#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = s.size();
        if (len <= 10) return {};
        unordered_set<string> st;
        vector<string> res;
        unordered_map<char, int> dict;
        unordered_set<int> set;        /* 存放出现次数≥1的原字符串映射的二进制bit 串(最后会自动被转为十进制数) */     
        dict['A'] = 0; // 二进制数00
        dict['C'] = 1; // 二进制数01
        dict['G'] = 2; // 二进制数10
        dict['T'] = 3; // 二进制数11
        for (int i = 0; i < s.size() - 9; i++)
        {
            int bin = 0;
            // 使用一个长度固定为10的滑动窗口, 对应一个字符串
            for (int j = i; j < i + 10; j++)
            {
                bin <<= 2;         /* 删掉滑动窗口最左侧滑出的那1个字母[由于每个字母(A、C、G、T之一)对应两个bit位, 故需要左移两个bit] */
                bin |= dict[s[j]]; /* 加入滑动窗口最右侧刚滑入的那1个字母: 把一个字母的二进制表示加到二进制串bin的末尾两个bit位(00) 上 */
            }
            string curStr = s.substr(i, 10);
            if (set.count(bin) && count(res.begin(), res.end(), curStr) == 0)
                res.push_back(curStr);
            else set.insert(bin);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto res = sol.findRepeatedDnaSequences(s);
    // 预期输出结果为: {"AAAAACCCCC","CCCCCAAAAA"}
    for (auto& num : res)
        cout << num << endl;
        
    return 0;
}