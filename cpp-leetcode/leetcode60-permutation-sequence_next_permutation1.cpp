#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        
        for (int i = 0; i < n; i++)
            s[i] += i + 1;
        for (int i = 0; i < k - 1; i++)
            next_permutation(s.begin(), s.end());
        return s;
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