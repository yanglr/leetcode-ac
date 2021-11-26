#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        const int N = nums.size();
        sort(begin(nums), end(nums));
        int left = 0; // 当前的最小距离可能是(有相等的数时), 也可能不是0, 搜索区间的起点从0开始比较稳妥
        int right = nums[N - 1] - nums[0];  // 最大距离
        while (left < right)
        {
            int guess = left + (right - left) / 2; // guess: mid
            if (possible(nums, guess, k))
                right = guess;
            else
                left = guess + 1;
        }
        return left;
    }
    bool possible(vector<int>& nums, int d, int k)
    {
        const int N = nums.size();
        long count = 0;
        int i = 0, j = 0;
        while (i < N || j < N)
        {
            while (j < N && nums[j] - nums[i] <= d) j++;
            count += j - i - 1;
            i++;
        }
        return count >= k;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 6, 1};
    int k = 3;
    auto res = sol.smallestDistancePair(nums, k);
    cout << res << endl;

    return 0;
}