#include<vector>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int len1 = s.size();
        int len2 = goal.size();
        if (len1 != len2) return false;
        if (s == goal) // 如果字符串s与字符串goal相同, 那么s中必须有某个字符至少出现了2次, 这样swap1次可以得到自己
        {
            unordered_map<char, int> dict;
            for (int i = 0; i < len1; i++)
            {
                auto ch = s[i];
                dict[ch]++;
                if (dict[ch] >= 2) return true;
            }
        }
        else if (s != goal) /* 两个字符串不相等的情况下如果要恰好swap一次就能相等, 那么两个字符串必然只有两个位置(不同index)的字符不一样 */
        {
            vector<int> indexes;
            for (int i = 0; i < len1; i++)
            {
                if (s[i] != goal[i]) indexes.push_back(i);
            }            
            if (indexes.size() != 2) return false;
            int pos1 = indexes.front();
            int pos2 = indexes.back();
            if (s[pos1] == goal[pos2] && s[pos2] == goal[pos1]) return true;
        }
        return false;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "ab";
    string goal = "ba";
    auto res = sol.buddyStrings(s, goal);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}