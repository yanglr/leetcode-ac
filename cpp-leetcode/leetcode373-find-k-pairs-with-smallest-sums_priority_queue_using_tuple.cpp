#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0)
            return res;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({nums1[0] + nums2[0], 0, 0});
        while (pq.size() && res.size() < k)
        {
            auto topP = pq.top();
            int i = get<1>(topP);
            int j = get<2>(topP);
            pq.pop();

            res.push_back({nums1[i], nums2[j]});
            if (j == 0 && i + 1 < n)
                pq.push({nums1[i + 1] + nums2[j], i + 1, j}); /* 关键操作 */

            if (i < n && j + 1 < m)
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 12;
    vector<int> nums1 = {1, 7, 11}, nums2 = {2, 4, 6};
    int k = 3;
    auto res = sol.kSmallestPairs(nums1, nums2, k);
        
    return 0;
}