#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        const int len = candyType.size();
        // len/2
        unordered_map<int, int> dict; // map: num -> count
        for (auto& num : candyType)
            dict[num]++;
        int res;
        if (dict.size() >= len/2)
            res = len/2;
        else res = dict.size();
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