#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> dict; // map: value -> count
        for (int i = 1; i <= n; i++)
            dict[i] = 0;
        for (auto& curNum : nums)
        {
            if (dict.count(curNum) == 0) dict[curNum] = 1;
            else dict[curNum]++;
        } 
        int missingNum, repeatNum;        
        for (auto& kvp : dict)
        {
            if (kvp.second == 0) missingNum = kvp.first;
            if (kvp.second == 2) repeatNum = kvp.first;
        }
        return {repeatNum, missingNum};
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