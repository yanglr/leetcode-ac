#include<vector>
#include<unordered_map>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> dict;
        int maxFreq = -1;
        int maxFreqCount = 0;
        for (auto& ch : tasks)
            dict[ch]++;
        for (auto& kvp : dict)
            maxFreq = max(maxFreq, kvp.second);
        for (auto& kvp : dict)
        {
            if (kvp.second == maxFreq) maxFreqCount++;
        }        
        int res = 0;
        const int len = tasks.size();
        res = max((maxFreq - 1)*(n+1) + maxFreqCount, len);
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    auto res = sol.leastInterval(tasks, n);
    cout << res << endl;

    return 0;
}