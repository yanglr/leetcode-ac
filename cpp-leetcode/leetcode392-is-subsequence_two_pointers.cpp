#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        // 双指针法
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {  /* s中的每一个字符t中都有, 且相对顺序一致 */
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};

// Test
int main()
{
    Solution sol;
    string s = "ab", t = "baab";
    auto res = sol.isSubsequence(s, t);
    return 0;
}