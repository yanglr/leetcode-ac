#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int _max = *max_element(nums.begin(), nums.end());
        int maxLen = to_string(_max).size();
        vector<pair<int, int>> kvVect;
        for (auto num : nums)
        {
            int curLen = to_string(num).size();
            string str = to_string(num);
            string str0 = str;
            int len0 = str0.size();
            if (_max != 0 && curLen < maxLen)
            {
                char firstDigit = to_string(num).front();
                while (curLen < maxLen - 1)
                {
                    str.push_back(str0[(maxLen - curLen) % len0]);
                    curLen++;
                }
                str.push_back(*max_element(str0.begin(), str0.end()));
            }
            int mask = stoi(str);
            kvVect.push_back({num, mask});
        }
        
        auto cmp = [](pair<int, int> p1, pair<int, int> p2)
        {
            return p1.second > p2.second;
        };
        sort(kvVect.begin(), kvVect.end(), cmp);
        
        string resultStr = "";        
        for (auto kvp : kvVect)
            resultStr += to_string(kvp.first);            
        if (resultStr.front() == '0') resultStr = to_string(stoll(resultStr));
        return resultStr;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {34323,3432};    
    // case1: {432,43243} , case2: {111311, 1113}, case3: {34323,3432}, case4: {0,0,0}
    auto res = sol.largestNumber(nums);
    cout << res << endl;

    return 0;
}