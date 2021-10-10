#include<vector>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obSet;
        for(const auto& vec: obstacles)
            obSet.insert(hashcode(vec[0], vec[1]));

        pair<int, int> pos = make_pair(0, 0);
        int index = 0;
        int res = 0;
        for(int& c : commands)
            if (c == -1) index = (index + 1) % 4;
            else if (c == -2) index = (index + 3) % 4;
            else {
                assert (c > 0);
                for (int i = 0 ; i < c; i++)
                {
                    pair<int, int> nextPos = make_pair(pos.first + dir[index][0], pos.second + dir[index][1]);
                    if (obSet.count(hashcode(nextPos.first, nextPos.second)) == 0)
                    {
                        pos = nextPos;
                        res = max(res, pos.first * pos.first + pos.second * pos.second);
                    }
                    else break;
                }
            }
        return res;
    }
private:
    long long hashcode(int a, int b)
    {
        return ((long long)a + 30000ll) * 60001ll + (long long)b + 30000ll;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> obstacles = {{2, 4}};
    vector<int> commands = {4, -1, 4, -2, 4};
    auto res = sol.robotSim(commands, obstacles);
    cout << res << endl;

    return 0;
}