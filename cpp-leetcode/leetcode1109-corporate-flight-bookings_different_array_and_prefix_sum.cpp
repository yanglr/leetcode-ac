#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> diff(n); // 差分数组
        for (vector<int>& booking : bookings) /* 区间[L, R]上做inc操作: diff[L] += c, diff[R+1] -= c; */
        {
            diff[booking[0] - 1] += booking[2];
            if (booking[1] < n)
                diff[booking[1]] -= booking[2];
        }
        vector<int> preSum = diff;
        // 反推出前缀和
        for (int i = 1; i < n; ++i)
            preSum[i] += preSum[i - 1];

        return preSum;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 5;  
    vector<vector<int>> updates = {{1,2,10}, {2,3,20}, {2,5,25}};
    auto res = sol.corpFlightBookings(updates, n);
    for (auto &num : res)
        cout << num << endl;
    
    return 0;
}