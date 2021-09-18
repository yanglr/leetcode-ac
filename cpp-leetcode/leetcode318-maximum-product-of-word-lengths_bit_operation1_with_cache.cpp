#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        const int len = words.size();
        vector<int> lens(len);     // cache lengths
        for (int i = 0; i < len; i++)
            lens[i] = words[i].size();

        int res = 0;
        vector<int> hash(len);
        for (int i = 0; i < len; i++)
        {
            for (auto& ch : words[i])           
                hash[i] |= 1 << (ch - 'a');
            for (int j = 0; j < i; j++)
            {
                if ((hash[i] & hash[j]) == 0)
                    res = max(res, lens[i] * lens[j]);                
            }
        }   
        return res;
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