#include<iostream>
#include<vector>
#include<numeric>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> cmpList;
        for (int i = 1; i <= len; i++)
            cmpList.push_back(i);
        auto sum1 = accumulate(nums.begin(), nums.end(), 0);
        unordered_set<int> set1(nums.begin(), nums.end());
        auto sum2 = accumulate(set1.begin(), set1.end(), 0);
        int repeatedNum = sum1 - sum2;
        int missingNum;
        for (auto &k : cmpList)
        {
            if (set1.count(k) == 0)
            {
                missingNum = k;
                break;
            }
        }
        
        return {repeatedNum, missingNum};
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2, 4};
    auto res = sol.findErrorNums(nums);
    for (auto &num : res)
        cout << num << endl;
    
    return 0;
}