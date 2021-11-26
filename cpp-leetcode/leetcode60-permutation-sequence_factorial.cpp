#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring> /* 含memset */
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int f[n]; // 记录阶乘 n! 的结果
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i < n; i++)
            f[i] = i*f[i-1];
        vector<int> digits; /* 1 <= n <= 9 */
        for (int i = 1; i <= n; i++)
            digits.push_back(i);

        k--; // 1-indexed -> 0-indexed
        string res = "";
        for (int i = n - 1; i >= 0; i--)
        {
            int index = k / f[i];
            res.push_back(digits[index] + '0');            
            digits.erase(digits.begin() + index);
            k = k % f[i];
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 4;
    int k = 9;
    auto res = sol.getPermutation(n, k);
    cout << res << endl;
    
    return 0;
}