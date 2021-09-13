#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        // n = points.length, n: [1, 500]
        const int n = points.size();
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> dict;
            for (int j = 0; j < n; j++)
            {
                const int dx = points[j][0] - points[i][0];
                const int dy = points[j][1] - points[i][1];
                long long d = dx*dx + dy*dy;
                if (i != j) dict[d]++;
            }            
            for (auto& [k, c] : dict)
                res += c*(c-1);               
        }
          
        return res;   
    }
};

// Test
int main()
{
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    auto res = sol.numberOfBoomerangs(points);
    cout << res << endl;

    return 0;
}