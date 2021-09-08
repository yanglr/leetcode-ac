#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int n = profits.size();
        vector<pair<int, int>> options; // map: 门槛capital -> profit
        for (int i = 0; i < n; i++)
            options.push_back({capital[i], profits[i]});
        sort(options.begin(), options.end()); // 用门槛从小到大的规则给pair排序
        priority_queue<int> pq; // 大顶堆放的是profit
        int count = 0;
        int i = 0;
        while (count < k)
        {
            while (i < n && options[i].first <= w)
            {
                pq.push(options[i].second);
                i++;
            }
            if (pq.empty()) break;
            w += pq.top();
            pq.pop();
            count++;
        }

        return w;
    }
};
// Test
int main()
{
    Solution sol;
    int k = 2, w = 0;
    vector<int> profits = {1, 2, 3}, capitals = {0, 1, 1};
    auto res = sol.findMaximizedCapital(k, w, profits, capitals);
    cout << res << endl;
    
    return 0;
}