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
    bool canOrderToSame(int i, int& n) /* 判断整数i是否重新排序后能和n相等 */
    {
        for (int d = 0; d <= 9; d++)  /* 枚举每一位的数字(0~9之间), 只要出现某一个数字在整数i和n中的数量不相等就返回false */
        {
            int count1 = countTimes(i, d);
            int count2 = countTimes(n, d);  
            if (count1 != count2) return false;
        }
        return true;
    }
    int countTimes(long int x, int d) /* 统计每一位的数digit(简写为d)在整数x中出现的次数 */
    {
        int count = 0;
        while (x)
        {
            if (x % 10 == d)
            count++;
            x = x / 10;
        }
        return count;
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