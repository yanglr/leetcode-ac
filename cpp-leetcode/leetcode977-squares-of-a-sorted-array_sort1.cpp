#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> squares;
        for (auto& num : nums) squares.push_back(num * num);
        sort(squares.begin(), squares.end());
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