#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            auto theIt = find(nums2.begin(), nums2.end(), nums1[i]);
            bool exist = false;
            for (auto it = theIt + 1; it < nums2.end(); it++)
            {
                if (*it > nums1[i])
                {
                    exist = true;
                    res[i] = *it;
                    break;
                }
            }
            if (!exist) res[i] = -1;
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    auto res = sol.nextGreaterElement(nums1, nums2);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}