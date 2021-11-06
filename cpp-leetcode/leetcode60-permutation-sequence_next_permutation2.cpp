#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        res.reserve(n);
        for (int i = 1; i != n + 1; i++)
            res.push_back(i + '0');
        while (--k)
            next_permutation(res.begin(), res.end());
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