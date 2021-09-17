#include<vector>
#include<string>
#include<unordered_map>
#include<bitset>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};

        vector<string> res;
        bitset<1 << 20> bin1;  /* 原字符串映射的二进制bit串第1次出现时, 在二进制数bin1中更新其标志位 */
        bitset<1 << 20> bin2;  /* 原字符串映射的二进制bit串再次出现时, 在二进制数bin2中更新其标志位 */

        unordered_map<char, int> dict;
        dict['A'] = 0; // 二进制数00
        dict['C'] = 1; // 二进制数01
        dict['G'] = 2; // 二进制数10
        dict['T'] = 3; // 二进制数11        

        int val = 0;
        /* 从前向后的滑动窗口(由长度为0开始, 长度每次增加1, 直到长度为10), 每次读入一个新的字母(2个bit), 并将其对应的二进制数与bin1相加 */
        for (int i = 0; i < 10; i++)
        {
            auto temp = (val << 2);
            val = temp | dict[s[i]];
        }
        bin1.set(val);

        int mask = (1 << 20) - 1; /* 掩码: 20个全1, 起到按长度20截断二进制串的作用, 只保留较低位的20个bit位 */
        for (int i = 10; i < s.size(); i++)
        {
            /*  计算以index = i 为结束位置且长度为10的字符串(其在原串s中index区间为[i-9, i])对应的二进制数: 滑动窗口继续右移, 
            去掉最高位的有效位(对应一个英文字母), 用当前新扫描进来的字母对应的二进制数替换最右边的两个bit位(00) */
            auto temp1 = val << 2;
            auto temp2 = temp1 & mask; /* & mask 是为了让二进制数的长度始终保持为20个bit, 否则会出现越界(bitset index outside of range) */
            val = temp2 | dict[s[i]];
            if (bin2[val]) continue; /* bin2[val]: 用来判断数val是否在二进制数bin2中已经有标志位了(之前已出现过2次, 这次是第3次出现). 
            具体步骤: 取出数val的对应的bit 标志位, 看结果是否为0x1, 为0x1表示已出现了2次, 后面不用继续统计次数了, 跳过之. 
            如果bin2[val]是0, 那还需要继续处理. */
            /* bin1[val]: 用来判断数val是否在二进制数bin1中已经有标志位了, 即判断结果是否为0x1, 为0x1表示之前已出现了1次, 
               此时可以加到结果集中, 并在二进制数bin2中更新其标志位  */
            if (bin1[val])
            {
                res.push_back(s.substr(i - 9, 10));
                bin2.set(val);
            }
            else bin1.set(val); /* 第1次出现, 在二进制数bin1中更新其标志位 */
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