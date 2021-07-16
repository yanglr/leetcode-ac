#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if (n == 0) st.insert("");
        else {
            vector<string> pre = generateParenthesis(n - 1);
            for (string str : pre) {
                for (int i = 0; i < str.size(); ++i) {
                    if (str[i] == '(') {
                        string s(str);
                        s.insert(s.begin() + i + 1, '(');
                        s.insert(s.begin() + i + 2, ')'); // 在每一个'('之后加入一对()
                        st.insert(s);
                    }
                }
                st.insert("()" + str);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};

// Test
int main()
{
    Solution sol;
    int n = 3;
    vector<string> res = sol.generateParenthesis(n);

    for(string str : res)
    {
        cout << str << endl;
    }

    return 0;
}