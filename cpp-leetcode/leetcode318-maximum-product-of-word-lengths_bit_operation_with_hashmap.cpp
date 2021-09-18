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
        unordered_map<int, int> maxlen; // 映射: one word's bit mask -> current largest word length
        for (string word : words)
        {
            int mask = 0;
            for (const char& ch : word)
                mask |= 1 << (ch - 'a');
            maxlen[mask] = max(maxlen[mask], (int) word.size());
        }
        int result = 0;
        for (auto& kv1 : maxlen)
        {
            for (auto& kv2 : maxlen)
            {
                if (!(kv1.first & kv2.first))
                    result = max(result, kv1.second * kv2.second);                        
            }    
        }
        return result;
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