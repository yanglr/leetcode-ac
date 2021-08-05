#include<algorithm>
#include<string>
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        // h: 小时, m: 分钟. 00:00 -> 11:59
        vector<string> res = {};
        for (int h = 0; h < 12; h++)
        {
            for (int m = 0; m < 60; m++)
            {
                if (count1(h) + count1(m) == turnedOn) 
                {
                    string mStr = m < 10 ? "0" + to_string(m) : to_string(m);
                    res.push_back(to_string(h) + ":" + mStr);
                }                
            }            
        }
        return res;
    }

    int count1(int n)
    {
        int count = 0;
        while (n > 0)
        {
            n = n & (n - 1);
            count++;
        }
        
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    int count = 6;
    auto res = sol.readBinaryWatch(count);
    for (auto str : res) cout << str << endl;

    return 0;
}