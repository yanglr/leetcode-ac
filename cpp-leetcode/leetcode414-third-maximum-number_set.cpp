#include<vector>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<long long> st(nums.begin(), nums.end());
        if (st.size() < 3) 
        {
            auto it = st.end();
            it--;
            return *it;
        }
        auto it = st.begin();
        advance(it, st.size() - 3); 
        return *it;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 4, 10};
    auto res = sol.thirdMax(arr);
    cout << res << endl;

    return 0;
}