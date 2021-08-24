#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

/*
插板法: 
1
⬇

1  2 => 312, 132, 123
2  1 => 321, 231, 213
*/

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        queue<vector<int>> q;
        q.push({nums[0]});

        for (int i = 1; i < nums.size(); i++)
        {
            int len = q.size();
            while (len--)
            {
                auto arr = q.front();
                q.pop();

                int M = arr.size();
                for (int k = 0; k <= M; k++)
                {
                    auto temp = arr;
                    temp.insert(temp.begin() + k, nums[i]);
                    q.push(temp);
                }                
            }
        }

        vector<vector<int>> results;
        while (!q.empty())
        {
            results.push_back(q.front());
            q.pop();
        }
        return results;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = sol.permute(nums);

    return 0;
}