#include<vector>
#include<algorithm>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        for (int i = 1; i <= 1e9; i *= 2)
        {
            if (canOrderToSame(i, n)) return true;
        }
        return false;
    }
    bool canOrderToSame(int i, int n) /* 判断整数i是否重新排序后能和n相等 */
    {
        unordered_map<char, int> dict1, dict2;
        for (auto ch : to_string(i)) dict1[ch]++; /* 转为字符串, 统计其中每一个字符出现的次数 */
        for (auto ch : to_string(n)) dict2[ch]++;
        return dict1 == dict2;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 24;
    auto res = sol.reorderedPowerOf2(n);
    cout << (res ? "True" : "False") << endl;

    return 0;
}