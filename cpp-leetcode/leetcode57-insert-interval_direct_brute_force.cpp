#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        merge(intervals);
        return intervals;
    }
    void merge(vector<vector<int>> &segs)
    {
        vector<vector<int>> res;
        sort(segs.begin(), segs.end());
        int start = INT_MIN, end = INT_MIN;        // 左端点最小值
        for (auto seg : segs)
            if (seg[0] > end)
            {
                if (start != INT_MIN) res.push_back({start, end});
                start = seg[0];
                end = seg[1];
            }
            else end = max(end, seg[1]);

        if (start != INT_MIN)  /* 循环结束时, 区间不空时, 把最后一个区间加进来 */
            res.push_back({start, end});

        segs = res;
    }  
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    auto res = sol.insert(intervals, newInterval); /* 加断点到下一行进行debug, 可以看到结果 */    
    return 0;
}