#include<algorithm>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        
        for(int i=0; i < nums.size(); i++)
        {
            map[nums[i]]++;
            if (map[nums[i]] == 2)
                return nums[i];
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int res = sol.findRepeatNumber(nums);
    cout << res << endl;

    return 0;
}