#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res;
        priority_queue<int> q;

        unsigned int i = 0;
        while(i < nums.size())
        {
            q.push(nums[i]);
            i++;
        }

        while(q.size() > nums.size() - k + 1)  // 把k-1个最大的弹出来
        {
            q.pop();
        }
        res = q.top();
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = { 3,2,1,5,6,4 };
    int k = 2;
    auto res = sol.findKthLargest(nums, k);
    cout << res << endl;
    return 0;
}