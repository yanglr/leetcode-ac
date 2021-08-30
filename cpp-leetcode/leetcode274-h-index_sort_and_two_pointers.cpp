#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& C) {
        sort(C.begin(), C.end());
        int len = C.size();
        int h = 0, j = len - 1;
        while (C[j] > h)
        {
            h++;
            if(j == 0) break;
            else j--;
        }
        return h;
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