#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        /* leftHeighest[i] (leftMaxH[i]): i左侧最高的bar; rightMaxH[i]: i右侧最高的bar */
        int N = height.size();
        vector<int> leftMaxH(N, 0);
        vector<int> rightMaxH(N, 0);

        for (int i = 1; i < N; i++)
            leftMaxH[i] = max(leftMaxH[i-1], height[i-1]);
        for (int i = N-2; i >= 0; i--)
            rightMaxH[i] = max(rightMaxH[i+1], height[i+1]);  /* rightMaxH[i]: i右侧(后面)最高的bar */
        int maxArea = 0;
        for (int i = 0; i < N; i++)
        {
            int h = min(leftMaxH[i], rightMaxH[i]) - height[i];
            h = (h >= 0 ? h : 0);
            maxArea += h * 1;
        }

        return maxArea;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto res = sol.trap(heights);
    cout << res << endl;

    return 0;
}