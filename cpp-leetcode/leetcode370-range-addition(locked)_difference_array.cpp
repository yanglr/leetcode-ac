#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
        // 技巧: 差分数组
        vector<int> diff(length + 1, 0);
        for (int i = 1; i <= updates.size(); i++)
        {
            vector<int> group = updates[i - 1];
            int startIndex = group[0];
            int endIndex = group[1];
            int inc = group[2];

            rangeInc(diff, startIndex, endIndex, inc);
        }
        // 反推出前缀和
        vector<int> preSum(length + 1, 0);
        for (int i = 0; i <= length - 1; i++)
            preSum[i + 1] = preSum[i] + diff[i];
        preSum.erase(preSum.begin()); /* 删除前缀和数组多余的数: 第一个元素0 */

        return preSum;
    }
    // [l, r]范围的差分数组的所有元素+c
    void rangeInc(vector<int>& diff, int l, int r, int c)
    {
        diff[l] += c;
        diff[r+1] -= c;
    }
};

// Test
int main()
{
    Solution sol;
    int len = 5;
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2, -2}};
    auto res = sol.getModifiedArray(len, updates);
    for (auto &num : res)
        cout << num << endl;
    
    return 0;
}