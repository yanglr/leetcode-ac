#include<vector>
#include<algorithm>
#include<iostream>
#include<numeric>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int m = 0; // 负数的个数
        for (auto& num : nums)
            if (num < 0) m++;
        auto sum = accumulate(nums.begin(), nums.end(), 0);            
        if (m == 0 && k % 2 == 0)
            return sum;
        else if (m == 0 && k % 2 == 1)
        {
            auto it = min_element(nums.begin(), nums.end());
            return sum - 2*(*it);
        }  
        else if (m > 0 && m >= k)
        {
            sort(nums.begin(), nums.end());
            int sum1 = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (i <= k-1) /* 题意: k >= 1, k-1不会成负数 */
                    sum1 += -nums[i]; 
                else sum1 += nums[i];                
            }                       
            return sum1;
        }
        else if (m > 0 && m < k)
        {
            if ((k - m) % 2 == 0)
            {
                int sum1 = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] < 0) 
                        sum1 += -nums[i]; 
                    else sum1 += nums[i];                
                }  
                return sum1;  
            }
            else {
                int sum1 = 0;
                for (int i = 0; i < nums.size(); i++)
                {
                    if (nums[i] < 0) 
                       nums[i] = -nums[i];    
                    sum1 += nums[i];            
                }                  
                sort(nums.begin(), nums.end());
                auto it = min_element(nums.begin(), nums.end());
                return sum1 - 2*(*it);                
            }
        }
        return 0;      
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {5, 6, 9, -3, 3};
    int k = 2;
    auto res = sol.largestSumAfterKNegations(nums, k);
    cout << res << endl;

    return 0;
}