#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int maxXCount = m, maxYCount = n;
        for (auto& op: ops)
        {
            maxXCount = min(maxXCount, op[0]);  /* 横向最大值数量取决于短板 */
            maxYCount = min(maxYCount, op[1]);  /* 纵向最大值数量取决于短板 */
        }
        return maxXCount * maxYCount;
    }
};

// Test
int main()
{  
    Solution sol;
    int m = 4, n = 6;
    vector<vector<int>> operations = {{2, 5}, {3, 2}};
    auto res = sol.maxCount(m, n, operations); // 预期结果是4
    cout << res << endl;

    return 0;
}