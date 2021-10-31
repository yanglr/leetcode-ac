#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    int res = INT_MAX;
    vector<int> buy;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        buy.resize(needs.size(), 0);
        dfs(price, special, needs, 0, 0);
        return res;
    }
    void dfs(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int money, int index)
    {
        if (index == special.size())
        { //当遍历完大礼包数组时，判断当前选择是否更优惠
            int extra = 0;
            for (int i = 0; i < needs.size(); i++)
            { // 将buy数组补到与needs数组相同
                extra += (needs[i] - buy[i]) * price[i];
            }
            res = min(res, money + extra);
            return;
        }
        for (int i = index; i <= special.size(); i++)
        {
            int j = 0;
            for (; j < needs.size() && i < special.size(); j++)
            { // 判断该大礼包是否可选，当不会多买时，便可选
                if (buy[j] + special[i][j] > needs[j])
                    break;
            }
            if (j == needs.size() || i == special.size())
            {
                for (int j = 0; j < needs.size() && i < special.size(); j++)
                { // 买入special[i][j]个j
                    buy[j] += special[i][j];
                }
                if (i < special.size()) money += special[i][needs.size()]; // 花钱special[i][needs.size()]买下该大礼包
                dfs(price, special, needs, money, i); // 递归
                for (int j = 0; j < needs.size() && i < special.size(); j++)
                {   // 回溯退货
                    buy[j] -= special[i][j];
                }
                if (i < special.size()) money -= special[i][needs.size()]; // 回溯退款
            }
        }
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> price = {2, 5};
    vector<int> needs = {3, 2};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    auto res = sol.shoppingOffers(price, special, needs);
    cout << res << endl;

    return 0;
}