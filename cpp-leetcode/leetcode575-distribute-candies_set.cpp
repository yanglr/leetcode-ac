#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int len = candyType.size();
        // len/2
        unordered_set<int> st(candyType.begin(), candyType.end());
        int res;
        if (st.size() >= len/2)
            res = len/2;
        else res = st.size();
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> candyType = {1,1,2,2,3,3};
    auto res = sol.distributeCandies(candyType);
    cout << res << endl;

    return 0;
}