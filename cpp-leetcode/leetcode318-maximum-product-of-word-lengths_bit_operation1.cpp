#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int len = words.size();
        int res = 0;
        vector<int> hash(len); /* 将所有单词哈希化, 原数组words中的每一个word对应一个映射后的二进制数 */
        for (int i = 0; i < len; i++)
        {
            for (auto& ch : words[i])           
                hash[i] |= 1 << (ch - 'a'); /* 用26个bit做哈希映射: 从低位到高位遍历, 如果一个字母出现, 则将其对应的bit位置为1 */
            for (int j = 0; j < i; j++)
            {
                if ((hash[i] & hash[j]) == 0) /* 如果两个hash值 hash[i] 与 hash[j]的按位与结果为0, 那么表示没共同的字母 */
                    res = max(res, int(words[i].size() * words[j].size()));   /* size()的返回值是unsigned int, 需要转换成int */              
            }
        }   
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> s = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef", "foo"};
    auto res = sol.maxProduct(s);
    // 预期输出结果为: 16
    cout << res << endl;
        
    return 0;
}