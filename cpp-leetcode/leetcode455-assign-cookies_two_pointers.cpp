#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        // 双指针
        int j = 0;  // 遇到满足条件的情形, j才移动一步(同时是一个计数器)      
        for (int i = 0; i < s.size() && j < g.size(); ++i) {
            if (s[i] >= g[j]) j++;
        }
        return j;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> s = {1,2,3};  // cookies we have
    vector<int> g = {3};
        
    int res = sol.findContentChildren(g, s);
    cout << res << endl;

    return 0;
}
