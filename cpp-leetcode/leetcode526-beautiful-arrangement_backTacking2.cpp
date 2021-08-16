#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> curGroup;
vector<vector<int>> allGroups(20, vector<int>());

class Solution {
public:
    bool used[20];
    int count;
    
    int countArrangement(int N)
    {
        curGroup.clear();
        for (int i = 1; i <= N; i++)
            allGroups[i].clear();
        
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (i % j == 0 || j % i == 0)
                {
                    allGroups[i].push_back(j);
                    // cout << i << '' << j << endl;
                }
            }
            curGroup.push_back(i);
        }

        auto cmp = [](const int& i, const int& j)
        {
            return allGroups[i].size() < allGroups[j].size();
        };
        sort(curGroup.begin(), curGroup.end(), cmp);

        count = 0;
        dfs(1, N);

        return count;
    }

    void dfs(int startNum, int maxNum)
    {
        // cout << p << ' ' << maxNum << endl;
        if (startNum == maxNum + 1)
        {
            count++;
            return;
        }
        int index = curGroup[startNum - 1];
        // cout << index << endl ;
        for (auto& num : allGroups[index])
        {
            if (used[num] == false)
            {
                used[num] = true;
                dfs(startNum + 1, maxNum);
                used[num] = false;
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    int num = 5;
    auto res = sol.countArrangement(num);
    cout << res << endl;

    return 0;
}