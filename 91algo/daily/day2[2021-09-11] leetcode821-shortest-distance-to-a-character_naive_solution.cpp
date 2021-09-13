#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        // 题意: 计算 abs[i] = indexGap(i, nearest_c), 1 <= s.length <= 10^4
        // 输出 abs[i]的数组
        vector<int> indexes;  // indexes of char c
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == c) indexes.push_back(i);
        }
        vector<int> res;
        for (int i = 0; i < s.size(); i++)
        {
            vector<int> gaps;  // gap for char s[i] to char c
            for (auto index : indexes)
                gaps.push_back(abs(index - i));
            auto it = min_element(gaps.begin(), gaps.end());
            res.push_back(*it);
        }        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "loveleetcode";
    char c = 'e';
    auto res = sol.shortestToChar(s, c);
    for (auto &num : res)
        cout << num << endl;

    return 0;
}