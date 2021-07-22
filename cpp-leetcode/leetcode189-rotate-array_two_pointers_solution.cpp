#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (nums.empty() || (k % n) == 0) return;
        
        int nowIndex = 0;
        int temp, cur = nums[0];
        // 双指针
        for (int j = 0, i = 0; j < n; j++)
        {
            temp = cur;
            nowIndex = (k + nowIndex) % n;
            cur = nums[nowIndex];
            nums[nowIndex] = temp;
            if (nowIndex == i)
            {
                nowIndex = ++i;
                cur = nums[nowIndex];
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    sol.rotate(nums, k);

    for (int num : nums)
        cout << num << endl;

    return 0;
}