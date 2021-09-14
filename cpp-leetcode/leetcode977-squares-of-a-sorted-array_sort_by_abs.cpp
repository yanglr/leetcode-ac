#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        auto cmp = [](const int& p1, const int& p2)
        {
            return abs(p1) < abs(p2);
        };
        sort(nums.begin(), nums.end(), cmp);
        for (auto& num : nums) squares.push_back(num * num);        
        return squares;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    auto res = sol.sortedSquares(nums);
    printf("%d ", res);
    return 0;
}