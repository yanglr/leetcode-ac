#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int len = s.size();
        if (len <= 10) return {};
        unordered_set<string> st;
        vector<string> res;
        for (int i = 0; i < len - 9; i++)
        {
            string subStr = s.substr(i, 10);
            if (st.count(subStr) && count(res.begin(), res.end(), subStr) == 0)
                res.push_back(subStr);
            else st.insert(subStr);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    auto res = sol.findRepeatedDnaSequences(s);
    // 预期输出结果为: {"AAAAACCCCC","CCCCCAAAAA"}
    for (auto& num : res)
        cout << num << endl;
        
    return 0;
}