#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        const int N = s.size();
        for (int i = 0; i < N; i++)
        {
            int len = 0;
            // 长度为奇数时
            while (i - len >= 0 && i + len < N && s[i - len] == s[i + len])
                len++;
            count += len; // 此时len = countOdd(满足条件的长度为奇数的回文子串的数量), len是对不同半径的计数器

            len = 0;
            // 长度为偶数时
            while (i - len >= 0 && i + 1 + len < N && s[i - len] == s[i + 1 + len])
                len++;
            count += len; // 此时 len = countEven(满足条件的长度为偶数的回文子串的数量)
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    string s = "abc";
    auto res = sol.countSubstrings(s);
    cout << res << endl;

    return 0;
}