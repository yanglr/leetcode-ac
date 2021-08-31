#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dict;
        for (auto& ch : s)
        {
            if (dict.find(ch) == dict.end())
                dict[ch] = 1;
            else dict[ch]++;
        }
        string res;
        vector<pair<char, int>> kvVect;
        for (auto kvp : dict)
            kvVect.push_back(kvp);        
        auto cmp = [](const pair<char, int>& p1, const pair<char, int>& p2)
        {
            return p1.second > p2.second;
        };
        sort(kvVect.begin(), kvVect.end(), cmp);
        for (auto kvp : kvVect)
        {
            while (kvp.second--)
                res.push_back(kvp.first);
        } 
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "BabBbBbBbbABBABBbAabbbGGGGKKKggggg";

    auto res = sol.frequencySort(str);
    cout << res << endl;
    
    return 0;
}