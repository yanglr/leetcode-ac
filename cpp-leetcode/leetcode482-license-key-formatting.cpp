#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        // 1.删除所有的-
        string newStr = "";
        for (auto ch : s)
        {
            if (ch != '-') 
            {
                if (ch >= 'a' && ch <= 'z') newStr.push_back(ch + 'A' - 'a');
                else newStr.push_back(ch);
            }
        }

        int len = newStr.size();
        // 2.从末尾开始loop, 每走k格加一个-
        for (int i = len - 1; i >= 0; i--)
        {
            int gap = len - 1 - i;
            if (gap > 0 && (gap % k == 0))
            {
                newStr.insert(newStr.begin() + i + 1, '-');
            }            
        }
        
        return newStr;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "5F3Z-2e-9-w";
    int k = 4;
    auto res = sol.licenseKeyFormatting(str, k);
    cout << res << endl;    

    return 0;
}