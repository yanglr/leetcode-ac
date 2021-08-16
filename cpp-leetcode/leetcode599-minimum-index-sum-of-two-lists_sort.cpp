#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {        
        vector<string> res;
        const int len1 = list1.size();
        const int len2 = list2.size();
        vector<pair<string, int>> kvVect;

        int indexSum = 0;
        for (int i = 0; i < len1; i++)
        {
            auto it = find(list2.begin(), list2.end(), list1[i]);
            if (it != list2.end())
            {
                indexSum = it - list2.begin() + i;
                kvVect.push_back({list1[i], indexSum});
            }
        }
        auto cmp = [](pair<string, int>& p1, pair<string, int>& p2)
        {
            if (p1.second == p2.second)
                return p1.first < p2.first;
            return p1.second < p2.second;
        };
        sort(kvVect.begin(), kvVect.end(), cmp);
        int minIndexSum = kvVect.front().second;
        for (auto &kvp : kvVect)
        {
            if (kvp.second == minIndexSum)
                res.push_back(kvp.first);            
        }
        
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> list1 = {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 = {"KFC","Burger King","Tapioca Express","Shogun"};
    auto res = sol.findRestaurant(list1, list2);
    for (auto str : res)
        cout << str << endl;
    
    return 0;
}