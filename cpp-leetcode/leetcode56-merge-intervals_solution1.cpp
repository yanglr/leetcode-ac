#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        vector<pair<int, int>> q; /* pair: (start, end) */
        vector<vector<int>> res;
        for (auto &range : intervals)
        {
            q.push_back({ range.front(), range.back() });
        }
        
        auto cmp = [](pair<int, int>& range1, pair<int, int>& range2)
        {
            return range1.first < range2.first; /* 按区间的start(下界)排序 */
        };
        sort(q.begin(), q.end(), cmp);        
    
        for (const auto& range : q) {
            // 无交集
            if (res.empty() || range.first > res.back().back()) {
                res.push_back({range.first, range.second});
            } else {  // 有交集: 只可能在 res 的右侧有交集, 因为已排序
                res.back().back() = max(res.back().back(), range.second);
            }
        }
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    auto res = sol.merge(intervals);  /* 加断点到这一行和下一行, debug时可看到结果 */

    return 0;
}