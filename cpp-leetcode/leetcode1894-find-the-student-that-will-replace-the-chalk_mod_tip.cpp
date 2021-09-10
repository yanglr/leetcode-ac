#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for (auto num : chalk)
            sum += num; // 求和
        k = k % sum;    // 小技巧: mod, 减小目标值 k 的规模
        int len = chalk.size();
        for (int i = 0; i < len; i++)
        {
            if (k < chalk[i]) return i; // 不够减时
            k -= chalk[i];
        }
        return -1;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> chalk = {3, 1, 7};
    int k = 30004001;
    int res = sol.chalkReplacer(chalk, k);
    cout << res << endl;
    
    return 0;
}