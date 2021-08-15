#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        vector<pair<int, int>> q;
        for (auto interval : intervals)
        {
            q.push_back({interval[0], 1});
            q.push_back({interval[1], -1});
        }
        q.push_back({newInterval[0], 1});
        q.push_back({newInterval[1], -1});

        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b)
        {
            if (a.first == b.first)
                return a.second > b.second;
            else return a.first < b.first;
        };

        sort(q.begin(), q.end(), cmp);
        int count = 0;
        int start, end;
        vector<vector<int>> results;
        for (auto x : q)
        {
            count += x.second;
            if (x.second == 1 && count == 1)
            {
                start = x.first;
            }
            else if (x.second == -1 && count == 0)
            {
                end = x.first;
                results.push_back({start, end});
            }
        }
        return results;
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