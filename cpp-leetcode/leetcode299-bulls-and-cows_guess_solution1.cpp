#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {  /* secret.length == guess.length */
        string res;
        int len1 = secret.size(), len2 = guess.size();
        int count1 = 0;  // 计数器: 统计 字符相同且index相等 的数量
        vector<char> arrS, arrG;
        for (int i=0; i < len1; i++)
        {
            if (secret[i] == guess[i]) 
                count1++;
            else 
            {
                arrS.push_back(secret[i]);
                arrG.push_back(guess[i]);             
            }
        }
        int count2 = 0;
        int len = arrG.size();
        for (int i = 0; i < len; i++)
        {
            auto it = find(arrS.begin(), arrS.end(), arrG[i]);
            if (it != arrS.end())
            {
                count2++;                
                if (it == arrS.end() - 1) arrS.pop_back();
                else arrS.erase(it);
            }            
        }        

        res = to_string(count1) + "A" + to_string(count2) + "B";
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string secret = "1122", guess = "2211";
    auto res = sol.getHint(secret, guess);
    cout << res << endl;

    return 0;
}