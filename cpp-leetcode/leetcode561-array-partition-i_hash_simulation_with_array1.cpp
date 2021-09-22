#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        vector<int> countDict(20001);
        for (int i = 0; i < nums.size(); i++)
            countDict[nums[i] + 10000]++; /* 数组中的数全加上10000映射到index >= 0的范围内, 方便实现数组模拟哈希表 */
        int res = 0;
        bool odd = true; // 第1个元素(index = 0)的编号为1, 是奇数
        for (int i = 0; i < countDict.size(); i++)
        {
            while (countDict[i] > 0)
            {
                if (odd)
                    res += (i - 10000);
                odd = !odd;
                --countDict[i];
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {6, 2, 6, 5, 1, 2};
    int res = sol.arrayPairSum(nums);
    cout << res << endl;

    return 0;
}