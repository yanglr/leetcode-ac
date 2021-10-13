#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int startMinu = getMinutes(startTime);
        int endMinu = getMinutes(finishTime);
        if (endMinu < startMinu) endMinu += 24 * 60;   /* case: ["20:00", "06:00"], 包括了 00:00 */
        else if (endMinu - startMinu < 15) return 0; /* case: ["00:47", "00:57"] */
        int validStart = startMinu % 15 != 0 ? (startMinu / 15 + 1) * 15 : startMinu / 15 * 15;
        int validEnd = endMinu / 15 * 15;
        return (validEnd - validStart) / 15;  /* 有效区间: 原区间的子区间, 两端均收缩, 即endTime/15向下取整 - startTime/15向上取整 */
    }
    int getMinutes(string ts)
    {
        int hour = stoi(ts.substr(0, 2));
        int minute = stoi(ts.substr(3, 2));
        return 60*hour + minute;
    }
};

// Test
int main()
{
    Solution sol;
    string start = "20:00";
    string end = "06:00";
    auto res = sol.numberOfRounds(start, end);
    cout << res << endl;

    return 0;
}