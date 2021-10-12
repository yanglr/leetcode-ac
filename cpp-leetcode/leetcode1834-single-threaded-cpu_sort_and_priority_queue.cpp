#include<vector>
#include<queue>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL; // pair: 处理时间 -> index
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        // 加入index, 题目要求在任务池中选任务时需要按下标排序, 下标小的排前面
        for (int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end()); // 根据先来先服务的规则, 按每个任务的开始时刻排序
        priority_queue<PLL, vector<PLL>, greater<>> pq;

        LL cur = 0;  // 记录当前时间点
        vector<int> res;
        for (int i = 0; i < tasks.size(); i++)
        {
            while (cur < tasks[i][0] && !pq.empty()) /* 先去任务池捞一下, 看有没有可以执行的任务, 如果有逐个执行 */
            {
                res.push_back(pq.top().second);                
                cur += pq.top().first;
                pq.pop();
            }
            if (cur < tasks[i][0]) cur = (LL)tasks[i][0];  /* 如果循环结束时, 时间片还没到达, 那就可以将时间直接跳到最近的下一个任务开始的时刻, 反正也是空等 */
            pq.push({tasks[i][1], tasks[i][2]});     
        }
        while (!pq.empty())  /* 再去任务池捞一下, 看有没有可以执行的任务, 如果有逐个执行 */
        {
            res.push_back(pq.top().second);
            cur += pq.top().first;
            pq.pop();            
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> tasks = {{1,2},{2,4},{3,2},{4,1}};
    auto res = sol.getOrder(tasks);
    for (auto& num : res)    
        cout << num << " ";

    return 0;
}