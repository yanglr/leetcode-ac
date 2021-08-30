#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& C) {
        // 举例: 0 1 3 5 6
        const int len = C.size();
        vector<int> bucket(len + 1, 0);
        for (auto& count : C)
            bucket[min(count, len)] += 1;  /* C中有重复数, 所以需要加上来 */
        int h = 0;
        int res = 0;
        for (int i = len; i >= 0 && h < i; i--)
        {
            if (h + bucket[i] > i)
            {
                res = i;
                break;
            }
            else {
                h += bucket[i];
                if (h <= i)
                    res = h;
            }
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> citations = {3, 0, 6, 1, 5};
    auto res = sol.hIndex(citations);
    cout << res << endl;

    return 0;
}