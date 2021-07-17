#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int left = 0;
        int right = len - 1;

        int maxArea = INT_MIN;        
        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            if(area > maxArea)
                maxArea = area;
            
            if(height[left] <= height[right])
                left++;
            else right--;
        }
        return maxArea;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int res = sol.maxArea(nums);
    cout << res << endl;

    return 0;
}