#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        const int len = digits.size();
        for(int i = len - 1; i >= 0; --i)
        {
            if(digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;   // 发现不需要继续进位时, 直接返回
            }
            if(digits.front() == 0)
                digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.plusOne(nums);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}