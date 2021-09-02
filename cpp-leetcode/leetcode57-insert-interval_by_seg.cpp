#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int k = 0;
        int len = intervals.size();

        // 原区间中, 左侧与新区间无交集的部分
        while (k < len && intervals[k][1] < newInterval[0])
            res.push_back(intervals[k++]);

        // 处理有交集的部分
        if (k < len) {
            newInterval[0] = min(newInterval[0], intervals[k][0]);

            while (k < len && intervals[k][0] <= newInterval[1]) 
                newInterval[1] = max(newInterval[1], intervals[k++][1]);
        }
        res.push_back(newInterval);

        // 原区间中, 右侧与新区间无交集的部分
        while (k < len && intervals[k][0] > newInterval[1])
            res.push_back(intervals[k++]);
        return res;        
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