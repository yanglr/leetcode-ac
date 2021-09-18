#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

/* 该暴力解法通过了32/167 个test case 后出现了超时TLE */
class Solution {
public:
    int maxProduct(vector<string>& words) {
        long maxProd = 0;
        unordered_map<string, int> dict; // string -> count
        for (auto &word : words)
            dict[word]++;
        vector<string> kvVect;
        for (auto &kvp : dict)
            kvVect.push_back(kvp.first);
        auto cmp = [](const string& s1, const string& s2)
        {
            return s1.size() > s2.size();
        };     
        sort(kvVect.begin(), kvVect.end(), cmp);
        for (int i = 0; i < kvVect.size(); i++)
        {
            for (int j = 0; j < kvVect.size(); j++)
            {
                long len1 = kvVect[i].size();
                long len2 = kvVect[j].size();                
                if (i != j && !hasCommonChar(kvVect[i], kvVect[j]) && len1 * len2 > maxProd)
                {
                    maxProd = max(maxProd, len1 * len2);
                }                
            }            
        }
        return maxProd;   
    }
    bool hasCommonChar(string s1, string s2)
    {
        unordered_set<char> st1(s1.begin(), s1.end());
        unordered_set<char> st2(s2.begin(), s2.end());
        bool exist = false;
        for (auto &key : s1)
        {
            if (count(s2.begin(), s2.end(), key))
                exist = true;
        }        
        return exist;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> s = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef", "foo"};
    auto res = sol.maxProduct(s);
    // 预期输出结果为: 16
    cout << res << endl;
        
    return 0;
}