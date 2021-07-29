#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        vector<vector<int>> res;
        vector<pair<int, int>> ranges; /* ranges 是 intervals 的另一种存储方式
                                       ** 扫描线算法: time, flag. 先自定义排序
                                       **           进来一个start, 计数器+1, 
                                       **           进来一个end, 计数器-1.
                                       **           计数器出现0 -> 1的转折点, 表示新的 start 进来了
                                       **           计数器出现1 -> 0的转折点, 表示所有 []括号成对, merge 结束   
                                       */
        for (auto &vect : intervals)
        {
            ranges.push_back({vect.front(), 1});
            ranges.push_back({vect.back(), -1});
        }        

        auto cmp = [](pair<int, int>& range1, pair<int, int>& range2)
        {
            if (range1.first == range2.first) /* 相等时, flag为 1 的放在前面 */
                return range1.second > range2.second;
            return range1.first < range2.first;
        };
        sort(ranges.begin(), ranges.end(), cmp);

        int sumCounter = 0;
        int start, end;
        for (auto range : ranges)
        {
            if (range.second == 1)
            {
                sumCounter++;
                if (sumCounter == 1)  // 转折点: 0 -> 1, 新的start进来了
                {
                    start = range.first;
                }                
            }
            else  /* -1 */
            {
                sumCounter--;
                if (sumCounter == 0)  // 转折点: 1 -> 0, merge结束, 记录结束时的区间右边界end
                {
                    end = range.first;
                    res.push_back({start, end});
                }                
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