#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int len = 1 << n; /* n: 格雷码中bit位的个数 */
        vector<int> grey(len, 0);
        int startPos = 0;
        for (int i = 0; i < len; i++)
        {
            grey[i] = i ^ (i >> 1);
            if (grey[i] == start)  /* 由于格雷码数组中每一个数都是不相等的, 所以这里加不加break语句都行 */
                startPos = i;
        }
        vector<int> res(grey.begin() + startPos, grey.end());
        res.insert(res.end(), grey.begin(), grey.begin() + startPos);
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 2, start = 3;
    auto res = sol.circularPermutation(n, start);
    for (auto x : res)
        cout << x << " ";
    return 0;
}