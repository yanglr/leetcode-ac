#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    unordered_map<string, int> memo;
    int N;
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        N = price.size();
        vector<vector<int>> specials; // 筛选出真正便宜的打包价
        for (int i = 0; i < special.size(); i++)
        {
            int sum = 0;
            for (int j = 0; j < N; j++)
                sum += special[i][j] * price[j];
            if (sum > special[i].back())
                specials.push_back(special[i]);
        }
        string key;
        for (int i = 0; i < N; i++)
            key += "0";
        memo[key] = 0;

        return dfs(price, specials, needs);
    }
    string getKey(vector<int> &needs)
    {
        string key;
        for (int i = 0; i < needs.size(); i++)
            key += to_string(needs[i]);
        return key;
    }
    int dfs(vector<int> &price, vector<vector<int>> &specials, vector<int> &needs)
    {
        string key = getKey(needs);
        if (memo.find(key) != memo.end())
            return memo[key];

        int res = INT_MAX;
        int special_used = 0;
        for (int i = 0; i < specials.size(); i++)
        {
            int canUse = 1; // canUse: 打包优惠能不能用, 当special的数量门槛高时无法使用
            for (int j = 0; j < N; j++)
            {
                if (specials[i][j] > needs[j])
                {
                    canUse = 0;
                    break;
                }
            }
            if (canUse == 1)
            {
                special_used = 1;
                vector<int> needs_temp = needs;
                for (int j = 0; j < N; j++)
                    needs_temp[j] = needs[j] - specials[i][j];
                res = min(res, specials[i][N] + dfs(price, specials, needs_temp));
            }
        }
        if (special_used == 0)
        {
            res = 0;
            for (int i = 0; i < N; i++)
                res += price[i] * needs[i];
        }
        memo[key] = res;
        return res;
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