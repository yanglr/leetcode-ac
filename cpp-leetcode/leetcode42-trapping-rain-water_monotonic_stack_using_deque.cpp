#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int maxArea = 0;
        deque<int> st;
        
        for (int i = 0; i < height.size(); i++)
        {
            while (!st.empty() && height[st.front()] < height[i])
            {
                int base = height[st.front()];
                st.pop_front();
                if (st.empty()) continue;
                int h = min(height[st.front()], height[i]) - base;
                int width = i - st.front() - 1;
                maxArea += h * width;
            }
            st.push_front(i);
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