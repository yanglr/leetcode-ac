// #include <algorithm>
// #include <vector>
// #include <cmath>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &num) {
        if (num.size() < 2)
            return 0;

        int _min = num[0], _max = num[0];
        for (int i = 1; i < num.size(); i++)
        {
            _min = _min > num[i] ? num[i] : _min;
            _max = _max < num[i] ? num[i] : _max;
        }

        // 将区间 [_min, _max] 分成n个size 为 (_max -_min)/n 的桶
        int bucket_size = (_max - _min) / num.size() + 1;

        // 遍历剩下的 n-2 个数, 确定它们该放在哪个桶里.
        // 当且仅当 (num[i]-_min)/m = k-1 时, num[i] 应该放到第k个桶 B[k] 中

        vector<vector<int>> buckets((_max - _min) / bucket_size + 1);
        // 对每一个桶 B[k], 计算其最大值、最小值, 确定它们该放在哪个桶里
        // 如果桶是空的, 把数据放进去, 不做其他操作
        // 如果桶里只有一个数, 确保这个数 num = _max = _min
        for (int i = 0; i < num.size(); i++)
        {
            int idx = (num[i] - _min) / bucket_size;
            if (buckets[idx].empty())
            {
                buckets[idx].push_back(num[i]);
                buckets[idx].push_back(num[i]);
            }
            else
            {
                buckets[idx][0] = buckets[idx][0] > num[i] ? num[i] : buckets[idx][0]; /* 更新当前桶的最大值 */
                buckets[idx][1] = buckets[idx][1] < num[i] ? num[i] : buckets[idx][1]; /* 更新当前桶的最小值 */
            }
        }

        // 计算maxGap
        int maxGap = 0;
        int prev = 0;
        for (int i = 1; i < buckets.size(); i++)
        {
            if (buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            maxGap = maxGap > gap ? maxGap : gap;
            prev = i;
        }
        return maxGap;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {3,6,9,1};

    auto res = sol.maximumGap(nums);
    cout << res << endl;

    return 0;
}