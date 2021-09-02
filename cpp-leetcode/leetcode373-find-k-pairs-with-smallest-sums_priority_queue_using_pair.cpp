#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> res;
        if (m == 0 || n == 0)
            return res;
        for (int i = 0; i < m; i++)
        {
            pq.push({ {nums1[i] + nums2[0]}, {i, 0} });
        }
        while (!pq.empty() && k-- > 0)
        {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            vector<int> group = {nums1[i], nums2[j]};
            res.push_back(group);
            if (j + 1 == n) continue;
            pq.push({{nums1[i] + nums2[j + 1]}, {i, j + 1}});
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