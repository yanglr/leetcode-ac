#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int res = 0;
        int curMax = 0;
        const int len = arr.size();
        for (int i = 0; i < len; i++)
        {
            curMax = max(curMax, arr[i]);
            if (i == curMax) res++; /* 当index = i处的数已经处于正确位置上时, 
                                    该数字及其前面相邻的数组成的片段已经有序。
                                    这个片段已处理完毕，可以为数量贡献1了。 */
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 2, 3, 4};
    int res = sol.maxChunksToSorted(nums);           
    cout << res <<endl;
    return 0;
}