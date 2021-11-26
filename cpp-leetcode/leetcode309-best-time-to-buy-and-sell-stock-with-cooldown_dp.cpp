#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int hold = INT_MIN, sold = 0, cooled = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            int preHold = hold;
            int preSold = sold;
            int preCooled = cooled;

            int p = prices[i];
            hold = max(preHold, preCooled - p);
            sold = preHold + p; /* 如果hold的初始值设置为0就会有问题了, 可以将hold的初始值设置为 INT_MIN */
            cooled = max(preCooled, preSold);
        }
        return max(sold, cooled);
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> prices = {1,2,3,0,2};
    auto res = sol.maxProfit(prices);
    cout << res << endl;
    
    return 0;
}