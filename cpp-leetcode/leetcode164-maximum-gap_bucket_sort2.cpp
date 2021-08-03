// #include <algorithm>
// #include <vector>
// #include <cmath>
#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int _max = *max_element(nums.begin(), nums.end());
        int _min = *min_element(nums.begin(), nums.end());
        int n = nums.size();
        if(n < 2) return 0;
        
        int d = max(1, (_max - _min) / (n - 1)); /* 桶间隔 d, 有些桶不需要填 */
        int bucketSize = (_max - _min) / d + 1;
        vector<pair<int, int>> bucket (bucketSize, {-1, -1});
        for(auto i : nums) {
            int index = (i - _min) / d;
            if (bucket[index].first == -1) {
                bucket[index].first = bucket[index].second = i;
            } else {
                bucket[index].first = min(bucket[index].first, i);
                bucket[index].second = max(bucket[index].second, i);
            }
        }
        int res = 0;
        int prev = -1;
        for (int i = 0; i < bucketSize; i++) {
            if (bucket[i].first == -1) continue;
            if (prev != -1) {
                res = max(res, bucket[i].first - bucket[prev].second);
            }
            prev = i;
        }
        return res;
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