#include <algorithm>
#include <vector>
#include<unordered_map>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy = score;
        int len = score.size();
        if (len == 1) return { "Gold Medal" };
        sort(score.begin(), score.end(), greater<int>());  /* 从大到小排序, 排序后长度不变, 故len还能用 */      
        // 将原位置上的每个数的rank放进dict
        unordered_map<int, string> rankDict;  // map: score -> rank (string)
        rankDict[score[0]] = "Gold Medal";
        rankDict[score[1]] = "Silver Medal";
        if (len > 2) rankDict[score[2]] = "Bronze Medal";        
        for (int i = 3; i < len; i++) rankDict[score[i]] = to_string(i + 1);

        vector<string> res = {};
        for (int i = 0; i < len; i++)
            res.push_back(rankDict[copy[i]]);
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> scores = {3,4,2,5,1};
    auto res = sol.findRelativeRanks(scores);
    for (auto num : res)
        cout << num << endl;

    return 0;
}