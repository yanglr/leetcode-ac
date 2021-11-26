#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

const int N = 5e4;   
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> dict(2*N + 1, 0); // dict[id]: value -> count
        vector<int> res;
        for (auto& num : nums)
            dict[num + N]++;
        for (int i = 0; i < dict.size(); i++)
        {
            while (dict[i] > 0)
            {
                res.push_back(i - N);
                dict[i]--;
            }
        }
        return res;
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {5, 1, 3, 1, 2, 3, 3};
    auto res = sol.sortArray(nums);
    for (auto& num : res)
        cout << num << " ";

    return 0;
}