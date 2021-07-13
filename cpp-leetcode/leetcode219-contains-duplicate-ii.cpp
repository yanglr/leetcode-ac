#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> map; // value -> index
        for (int i = 0; i < nums.size(); i++)
        {
            if (map.find(nums[i]) != map.end() && abs(map[nums[i]] - i) <= k)
                return true;
            else {
                map[nums[i]] = i;
            }
        }

        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,1};
    int k = 3;

    bool res = sol.containsNearbyDuplicate(nums, k);
    cout << (res == true ? "true" : "false") << endl;

    return 0;
}