#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    using ll = long long;
    int numberOfArithmeticSlices(vector<int> &A) {
        if (A.size() < 3)
            return 0;
        int res = 0, n = A.size();
        unordered_map<ll, set<int>> hashmap;
        unordered_set<int> uniqueNums;
        for (int i = 0; i < n; i++)
            hashmap[A[i]].insert(i);
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                ll d = (ll)A[j] - A[i];
                if (d == 0 && uniqueNums.count(A[i]) > 0)
                    continue;
                if (d == 0)
                {
                    uniqueNums.insert(A[i]);
                    calc(hashmap[A[i]].size(), 0, res);
                    continue;
                }
                dfs(hashmap, j, A[j], d, 2, res);
            }
        }
        return res;
    }

    void dfs(unordered_map<ll, set<int>> &hashmap, int idx, int prev, ll d, int n, int &res)
    {
        ll next = prev + d;
        auto it = hashmap.find(next);
        if (it == hashmap.end())
        {
            calc(n, d, res);
            return;
        }
        auto iter = it->second.upper_bound(idx);
        if (iter == it->second.end())
        {
            calc(n, d, res);
            return;
        }
        for (int i = 0; iter != it->second.end(); i++, iter++)
            dfs(hashmap, *iter, next, d, i == 0 ? n + 1 : 3, res);
    }
    
    void calc(int n, ll d, int &res)  // Compute combination C(n, d)
    {
        if (n < 3)
            return;
        if (d != 0)
            res += n - 2;
        else
            res += pow(2, n) - 1 - n - n * (n - 1) / 2; // C(n,0)+C(n,1)+...C(n,n) = 2^n
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nhashmap = { 1, 1, 2, 3, 4, 5 };
    auto res = sol.numberOfArithmeticSlices(nhashmap);
    cout << res << endl;
    
    return 0;
}