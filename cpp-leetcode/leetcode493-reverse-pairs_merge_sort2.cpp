#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int res = 0;
    int temp[50001];
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        helper(nums, sorted, 0, n - 1);
        return res;
    }
    void helper(vector<int>& nums, vector<int>& sorted, int a, int b)
    {
        if (a >= b) return;
        int mid = a + (b - a) / 2;
        helper(nums, sorted, a, mid);
        helper(nums, sorted, mid + 1, b);

        for (int j = mid + 1; j <= b; j++)
        {
            auto it = upper_bound(sorted.begin() + a, sorted.begin() + mid + 1, 2 * (long)nums[j]);
            res += sorted.begin() + mid + 1 - it;
        }
        int i = a, j = mid + 1, p = 0;
        while (i <= mid && j <= b)
        {
            if (sorted[i] <= sorted[j])
            {
                temp[p] = sorted[i];
                i++;
            }
            else
            {
                temp[p] = sorted[j];
                j++;
            }
            p++;
        }
        while (i <= mid)
        {
            temp[p] = sorted[i];
            i++;
            p++;
        }
        while (j <= b)
        {
            temp[p] = sorted[j];
            j++;
            p++;
        }
        for (int i = 0; i < b - a + 1; i++)
            sorted[a + i] = temp[i];
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.reversePairs(nums);
    cout << res << endl;

    return 0;
}