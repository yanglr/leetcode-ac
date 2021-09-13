#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());

        long arrSum = 0;
        long sortedSum = 0;
        int maxCount = 0;
        int n = arr.size();        
        for (int i = 0; i < n; i++)
        {
            arrSum += arr[i];
            sortedSum += sortedArr[i];
            if (arrSum == sortedSum)   /* 当区间[0, i]中的数已经处于正确的区间上时, 
                                    该数字及其前面相邻的数组成的片段只要排序就满足要求了。
                                    这个片段已处理完毕，可以为数量贡献1了。 */
                maxCount++;
        }
        return maxCount;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 1, 3, 4, 4};
    int res = sol.maxChunksToSorted(nums);           
    cout << res <<endl;
    return 0;
}