#include<vector>
#include <numeric>   /* 含有 accumulate 函数 */
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int nums[2] = {a, b};
        return accumulate(begin(nums), end(nums), 0);
    }
};

// Test
int main()
{
    Solution sol;
    int a = 10;
    int b = -3;
    auto res = sol.getSum(a, b);
    cout << res << endl;
    
    return 0;
}