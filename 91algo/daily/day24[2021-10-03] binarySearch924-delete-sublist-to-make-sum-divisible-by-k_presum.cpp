#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int floorMod(const int& a, const int& b)
{
    return (a % b + b) % b;
}	
int solve(vector<int>& nums, int k) {
    int allSum = 0;
    for (int& num : nums)
        allSum += num;

    allSum = floorMod(allSum, k);
    unordered_map<int, int> dict; // dict: 某个前缀和%k得到的余数->pos
    dict[0] = -1;

    int preSum = 0;
    int minLen = nums.size();
    for (int i = 0; i < nums.size(); i++) {
        preSum += nums[i];
        int mod = floorMod(preSum, k);
        dict[mod] = i;

        if (dict.count(floorMod(preSum - allSum, k)))
            minLen = min(minLen, i - dict[floorMod(preSum - allSum, k)]);
    }
    return minLen == nums.size() ? -1 : minLen;
}

// Test
int main()
{
    vector<int> A = {1, 8, 6, 4, 5};
    int k = 7;
    auto res = solve(A, k);
    cout << res << endl;

    return 0;
}