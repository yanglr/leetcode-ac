#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dict) {
        string res = "";
        for (string& curStr : dict)
        {
            int i = 0;
            for (char& ch : s)
            {
                if (i < curStr.size() && ch == curStr[i]) i++;
            }
            if (i == curStr.size())  /* 指针i能走到末尾, 说明是可以做到的 */
            {
                if (res == "") res = curStr;
                else if (curStr.size() > res.size() || (curStr.size() == res.size() && curStr < res))
                    res = curStr;
            }
        }
        // 存在时返回相应值, 不存在时返回空串
        return res;
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