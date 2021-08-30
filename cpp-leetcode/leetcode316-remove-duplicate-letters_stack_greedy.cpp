#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char, int> chDict;
        unordered_map<char, bool> used;
        for (auto ch : s)
            chDict[ch]++;
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            if (used[ch] == true)
                chDict[ch]--;
            else if (st.empty() || st.top() < ch)
            {
                st.push(ch);
                used[ch] = true;
                chDict[ch]--;
            }
            else
            {
                while (!st.empty() && st.top() >= ch && chDict[st.top()] > 0)
                {
                    used[st.top()] = false;
                    st.pop();
                }
                st.push(ch);
                chDict[ch]--;
                used[ch] = true;
            }
        }
        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "cbacdcbc";
    auto res = sol.removeDuplicateLetters(s);
    // 预期结果为 "acdb"
    cout << res << endl;

    return 0;
}
