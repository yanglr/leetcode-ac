#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int left = 0, right = nums[N - 1] - nums[0];
        while (left < right)
        {
            int mid = (right - left) / 2 + left;
            int count = 0;
            int i = 0;
            for (int j = 0; j < N; j++)
            {
                while (nums[j] - nums[i] > mid)
                    i++;
                count += j - i;
            }
            if (count >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
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