#include<vector>
#include<unordered_map>
#include<deque>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict; /* 映射: nums2数组中每个数 -> index, 而由于nums1数组是其子集, 那nums1的数均能在dict的key中找到 */
        deque<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) /* 从后往前遍历, 维护一个单调递减栈, 遇到比top位置index在原数组中的大的数时就不断得弹出直到新来的数<=top对应的数, 否则就压入 */
        {
            while (!st.empty() && nums2[i] > nums2[st.back()])
                st.pop_back();
            
            dict[nums2[i]] = st.empty() ? -1 : nums2[st.back()];
            st.push_back(i);
        }
        vector<int> res(nums1.size());
        for (int i = 0;  i < nums1.size(); i++)
            res[i] = dict[nums1[i]];
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