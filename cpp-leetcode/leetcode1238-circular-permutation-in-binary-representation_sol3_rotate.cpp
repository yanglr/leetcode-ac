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
            if (grey[i] == start)
                startPos = i;
        }
        rotate(grey.begin(), grey.begin() + startPos, grey.end()); /* 原地做rotate操作得到想要的数组part2+part1 */
        return grey;
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