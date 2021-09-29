#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len = machines.size();
        int sum = 0;
        for (auto &num : machines)
            sum += num;
        if (sum % len != 0) return -1;
        int avg = sum / len;
        int res = 0;
        int totalDiff = 0;   // 整体的净流量偏差
        int curMax = 0;
        for (int &num : machines)
        {
            int curDiff = num - avg;  /* 当前洗衣机的流量偏差 */
            totalDiff += num - avg;
            if (curDiff >= 0)
                curMax = max(curDiff, abs(totalDiff));
            else curMax = max((abs(curDiff) + 1)/2, abs(totalDiff)); /* 一个洗衣机一次最多只能移出去1件衣服, 但可以一次接收最多2件衣服。+1是为了统一处理curDiff是奇数、偶数的情形 */
            res = max(res, curMax);
        };
        return res;
    }
};
// Test
int main()
{
    Solution sol;
    vector<int> machines = {3, 8, 4};
    auto res = sol.findMinMoves(machines);
    cout << res << endl;

    return 0;
}