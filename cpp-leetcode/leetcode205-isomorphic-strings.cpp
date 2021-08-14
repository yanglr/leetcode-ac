#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sFirstIndex;
        vector<int> tFirstIndex;
        for (auto ch : s)
        {
            int firstIndex = s.find_first_of(ch);
            sFirstIndex.push_back(firstIndex);
        }
        for (auto ch : t)
        {
            int firstIndex = t.find_first_of(ch);
            tFirstIndex.push_back(firstIndex);
        }
        return sFirstIndex == tFirstIndex;   
    }
};

// Test
int main()
{
    Solution sol;
    string s = "paper", t = "title";
    auto res = sol.isIsomorphic(s, t);

    cout << (res == true ? "True" : "False") << endl;

    return 0;
}