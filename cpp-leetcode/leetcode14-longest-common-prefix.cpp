#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 思路: 先将vector中第1个string 作为prefix初始值，然后取后面的string进行判断，更新prefix
        if(strs.empty()) return "";
        string prefix = strs.front();  // strs[0]

        for (int i = 1; i < strs.size(); i++)
        {
            const string& curStr = strs[i];

            int k = 0;
            while (k < min(prefix.length(), curStr.length()))
            {
                if (prefix[k] != curStr[k])
                {
                    break;                   // 每次都找当前最新的prefix与当前str的公共前缀
                }
                k++;
            }
            prefix = prefix.substr(0, k);
        }
        
        return prefix;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> input = {"flower","flow","flight"};
    string res = sol.longestCommonPrefix(input);
    cout << res << endl;

    return 0;
}