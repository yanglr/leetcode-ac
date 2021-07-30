#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> dict;
        for (char ch : s)
            dict[ch]++;
        for (int i = 0; i < s.size(); ++i) {
            if (dict[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "leetcode";
    auto res = sol.firstUniqChar(str);
    cout << res << endl;

    return 0;
}