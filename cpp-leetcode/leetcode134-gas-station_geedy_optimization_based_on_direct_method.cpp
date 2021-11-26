#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int N = gas.size();
        int j = 0;
        for (int i = 0; i < N; )
        {
            int remain = 0; // 记录当前总的油量
            for (j = 0; j < N; j++) // 向前走j个站点后到达站点k
            {
                int k = (i + j) % N; // 环形, 可能 i + j可能比较大
                remain += gas[k] - cost[k];
                if (remain < 0) break;
            }
            if (j == N) return i; // 恰好走了一圈
            i = i + j + 1; // 跳到下一个有可能的i 继续枚举
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    auto res = sol.canCompleteCircuit(gas, cost);
    cout << res << endl;

    return 0;
}