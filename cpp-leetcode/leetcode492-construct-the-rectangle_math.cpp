#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        /* 1 <= area <= 10^7 */
        int m = sqrt(area);
        int W = m;
        int i; // i 是 宽度W
        for (i = m; i >= 1; i--)
        {
            if (area % i == 0)
                break;
        }
        return {area/i, i}; // L = area/i;
    }
};
// Test
int main()
{
    Solution sol;
    int n = 122122;
    auto res = sol.constructRectangle(n);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}