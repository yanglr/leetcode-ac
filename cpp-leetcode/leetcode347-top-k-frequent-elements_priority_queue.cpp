#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int, int> dict; // map: value -> count
        for (auto num : nums)
        {
            if (dict.find(num) == dict.end()) dict[num] = 0;
            else dict[num]++;
        }
        auto cmp = [](pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second < p2.second;  /* 大顶堆, p2代表顶部值 */
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);
        for (auto kvp : dict) q.push(kvp);
        while (k > 0)
        {
            res.push_back(q.top().first);
            q.pop();

            k--;
        }

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    auto res = sol.topKFrequent(nums, k);
    
    for (auto num : res) cout << num << endl; 

    return 0;
}
