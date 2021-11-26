#include<vector>
#include<queue>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> st;
        deque<string> q;
        vector<string> res;
        if (isValid(s))
        {
            res.push_back(s);
            return res;
        }
        unordered_set<string> visited;
        q.push_back(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                string curStr = q.front();
                q.pop_front();
                for (int j = 0; j < curStr.size(); j++)
                {
                    if (curStr[j] != '(' && curStr[j] != ')')
                        continue;
                    string newStr = curStr.substr(0, j) + curStr.substr(j + 1, curStr.size() - 1 - j);
                    if (visited.count(newStr))
                        continue;
                    if (isValid(newStr))
                    {
                        found = true;
                        st.insert(newStr);
                    }
                    visited.insert(newStr);
                    q.push_back(newStr);
                }
            }
            if (found) break;
        }
        vector<string> temp(st.begin(), st.end());
        res.insert(res.end(), temp.begin(), temp.end());
        if (res.size() == 0)
            res.push_back(s);
        return res;
    }
    /* 判断str中的的括号表达式是否是合法的 */
    bool isValid(string str)
    {
        int leftPar = 0;
        int index = 0;
        while (index < str.size())
        {
            if (str[index] == '(')
                leftPar++;
            else if (str[index] == ')')
            {
                if (leftPar == 0)
                    return false;
                leftPar--;
            }
            index++;
        }
        return leftPar == 0;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "(a)())()";
    auto res = sol.removeInvalidParentheses(s);
    for (auto& str : res)
        cout << str << endl;

    return 0;
}