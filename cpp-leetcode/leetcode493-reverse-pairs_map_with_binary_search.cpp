#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long LL;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        map<LL, int> dict; // map: value -> count
        int res = 0;
        for (auto& num : nums)
        {
            LL target = (LL)2*num;
            auto it = dict.upper_bound(target); // 找到第1个满足要求的数key1, 那哈希表中排在key1后面的数(比key1更大)也全满足 > 2*num
            if (it != dict.end())
            {
                for (auto it1 = it; it1 != dict.end(); it1++)
                    res += it1->second;
            }        
            if (dict.count(num) > 0)
                dict[num]++; 
            else dict[num] = 1;      
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.reversePairs(nums);
    cout << res << endl;

    return 0;
}