#include <algorithm>
#include <vector>
#include<unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict1;  // map: value -> count
        unordered_map<int, int> dict2;
        unordered_map<int, int> interDict;
        for (auto n : nums1)
        {
            if (dict1.find(n) == dict1.end()) dict1[n] = 1;
            else dict1[n]++;
        }
        for (auto n : nums2)
        {
            if (dict2.find(n) == dict2.end()) dict2[n] = 1;
            else dict2[n]++;
        }
        for (auto n : nums1)
        {
            if (dict2.find(n) != dict2.end()) interDict[n] = min(dict1[n], dict2[n]);
        }
        vector<int> res;
        for (auto kvp : interDict)
        {
            int count = kvp.second;
            while(count > 0)
            {
                res.push_back(kvp.first);                
                count--;
            }
        }  
        return res;              
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    auto res = sol.intersect(nums1, nums2);
    for (auto num : res)
        cout << num << endl;

    return 0;
}