#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        vector<string> res;
        for (string& str : dict)
        {
            int i = 0;
            for (char& ch : s)
            {
                if (i < str.size() && ch == str[i]) i++;
            }
            if (i == str.size())  /* 指针i能走到末尾, 说明是可以做到的 */
                res.push_back(str);
        }
        if (res.empty()) return "";
        auto cmp = [](const string& s1, const string& s2)
        {
            if (s1.size() == s2.size())
                return s1 < s2;            
            return s1.size() > s2.size();
        };
        sort(res.begin(), res.end(), cmp);
        return res.front();
    }
};

// Test
int main()
{
    Solution sol;
    string str = "abpcplea";
    vector<string> dict = {"ale", "apple", "monkey", "plea"};
    auto res = sol.findLongestWord(str, dict);
    cout << res << endl;

    return 0;
}