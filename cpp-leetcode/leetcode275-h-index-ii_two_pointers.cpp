#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& C) {
        const int len = C.size();
        int i = 0, j = len - 1; // 双指针: i从0扫描到目标结果h时结束, j从len-1扫描到0, 扫描到0时break
        while (C[j] > i)
        {
            i++;
            if (j == 0) break;
            else j--;
        }
        return i;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> C = {1, 3, 2, 2, 5, 2, 3, 7};
    auto res = sol.hIndex(C);
    cout << res << endl;
    
    return 0;
}