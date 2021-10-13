#include<vector>
#include<map>
#include<regex>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    string res = "";
    string largestTimeFromDigits(vector<int>& A)
    {
        regex pattern("([0-1][0-9]:[0-5][0-9])|([2][0-3]:[0-5][0-9])");
        map<int, int> dict; // 存储每个数字digit出现的次数
        for (int i = 0; i < A.size(); i++)
            dict[A[i]]++;

        string str = "";
        backTrack(dict, str, pattern);
        return res;
    }
    void backTrack(map<int, int> dict, string str, regex& pattern)
    {
        if (str.length() == 2)
            str += ":";

        if (str.length() == 5)
        {
            if (regex_match(str, pattern))
                res = max(res, str); //valid time

            return;
        }
        for (auto it = dict.begin(); it != dict.end(); it++)
        {
            if (it->second != 0)
            {
                int val = it->first;
                dict[val]--;
                backTrack(dict, str + to_string(val), pattern);
                dict[val]++;
            }
        }
    }    
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 6, 6};
    auto res = sol.largestTimeFromDigits(nums);
    cout << res << endl;

    return 0;
}