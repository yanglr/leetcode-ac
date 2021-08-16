#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {        
        vector<string> res;
        unordered_map<string, int> dict;  // map: string -> index
        
        int index = 0;       
        for (auto &s : list1)
        {
            index++;
            dict[s] = index;    
        }

        int minIndexSum = INT_MAX;
        index = 0;
        for (auto &str : list2)
        {
            index++;
            if (dict[str] > 0)
            {
                int indexSum = index + dict[str];
                if (indexSum < minIndexSum)
                {
                    res.clear();                 // 记住: 这里必须清空
                    minIndexSum = indexSum;
                }
                if (indexSum == minIndexSum)
                    res.push_back(str);            
            }            
        }        

        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2 = {"KFC", "Burger King", "Tapioca Express", "Shogun"};
    auto res = sol.findRestaurant(list1, list2);
    for (auto str : res)
        cout << str << endl;

    return 0;
}