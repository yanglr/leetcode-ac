#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int minCharacters(string a, string b) 
    {
        vector<int> freqA(26); // 词频数组
        vector<int> freqB(26);
        for (auto& ch : a) freqA[ch - 'a']++;
        for (auto& ch : b) freqB[ch - 'a']++; 
        
        int res = INT_MAX;
        for (int key = 0; key < 26; key++) // key: 每个字母在词频数组中对应的index
        {
            if (key > 0) // 注意: 分界线不可能是字母'a'
            {
                // case1: max(a) < min(b)
                int changes = 0;
                for (int i = key; i < 26; i++)
                    changes += freqA[i];  // 把字符串a中 > key对应的字母 的字母改小              
                for (int i = 0; i < key; i++)
                    changes += freqB[i];
                res = min(res, changes);  
                
                // case2: max(b) < min(a)
                changes = 0;
                for (int i = 0; i < key; i++)
                    changes += freqA[i]; // 把a中 < key对应的字母 的字母改大
                for (int i = key; i < 26; i++)
                    changes += freqB[i];                  
                res = min(res, changes);
            }
            // case3: b只含1种字母, a也只含这一种字母
            int changes = 0;
            for (int i = 0; i < 26; i++)
                if (i != key)
                {
                    changes += freqA[i];
                    changes += freqB[i];
                }
            res = min(res, changes);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string A = "dabadd", B = "cda";
    auto res = sol.minCharacters(A, B);
    cout << res << endl;

    return 0;
}