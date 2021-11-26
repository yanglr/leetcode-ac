#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& R) { /* R: 代表ranges */
        auto cmp = [](const vector<int>& p1, const vector<int>& p2)
        {
            return p1[1] < p2[1];
        };
        sort(R.begin(), R.end(), cmp);
        const int len = R.size();
        if (R.empty()) return 0;
        int maxRemain = 1; // maxRemain: 最多保留下来多少个区间
        int curRight = R[0][1];
        for (int i = 1; i < len; i++)
        {
            if (R[i][0] >= curRight) /* 新来的区间的左边界R[i][0] 与当前区间的右边界比较, 如果≥成立说明可以再留下1个新的区间 */
            {
                maxRemain++;
                curRight = R[i][1];
            }
        }    
        return len - maxRemain;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> ranges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    auto res = sol.eraseOverlapIntervals(ranges);
    cout << res << endl;

    return 0;
}