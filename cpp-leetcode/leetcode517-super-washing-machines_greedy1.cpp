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
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        // 两端的两个洗衣机向一个传递一个方向, 需要提前处理, 其他洗衣机都有两个左右两个方向的输入、输出
        right[0] = machines[0] - avg;
        left.back() = machines.back() - avg;        
        for (int i = 1; i < len - 1; i++)
        {
            left[i] = -right[i-1];
            right[i] = machines[i] - avg - left[i];
        }
        int res = 0;
        for (int i = 0; i < len; i++) /* 计算输出净值的最大值 */
        {
            int curMax = 0;
            if (left[i] >= 0) curMax += left[i];
            if (right[i] >= 0) curMax += right[i];
            res = max(res, curMax);
        }                
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