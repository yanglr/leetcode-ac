#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int>& p1, const vector<int>& p2)
        {
            if (p1[0] != p2[0])
                return p1[0] > p2[0];
            return p1[1] < p2[1];
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (int i = 0; i < people.size(); i++)
        {
            if (res.empty())
            {
                res.push_back(people[i]);
                continue;
            }
            int pos = people[i][1];
            res.insert(res.begin() + pos, people[i]);
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    auto res = sol.reconstructQueue(people);
    for (auto& row : res) // 遍历每一行
    {
        for (auto& elem : row) // 输出每一个元素
            cout << elem << " ";  
        cout << "\n";
    }

    return 0;
}