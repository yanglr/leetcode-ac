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
    bool canOrderToSame(int i, int& n)   /* 判断整数i是否重新排序后能和n相等 */
    {
        vector<int> dict1(11), dict2(11);
        for (int d = 0; d <= 9; d++)
        {
            dict1[d] = countTimes(i, d);
            dict2[d] = countTimes(n, d);            
        }
        return dict1 == dict2;
    }
    int countTimes(long int x, int d)  /* 计算每一位的数digit(简写为d)在整数x中出现的次数 */
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