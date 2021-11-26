#include<vector>
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 1e5;
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        bool flags[2 * N + 1]; /* 标记当前num是否是重复出现, -10^5 <= candyType[i] <= 10^5 */
        fill(flags, flags + 2 * N + 1, false);
        int count = 0;
        int half = candyType.size() / 2;
        for (auto &candy : candyType)
        {
            candy += N;
            if (!flags[candy])
            {
                if (++count >= half)
                    return count;
                flags[candy] = true;
            }
        }
        return count;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> candyType = {1, 1, 2, 2, 3, 3};
    auto res = sol.distributeCandies(candyType);
    cout << res << endl;

    return 0;
}