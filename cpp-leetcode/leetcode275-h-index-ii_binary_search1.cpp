#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& C) {
        const int n = C.size();
        if (n == 1 && C[0] == 0) return 0;
        if (n == 1 && C[0] >= 1) return 1;   
             
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left)/2;
            int count = n - mid;    // count: 引用次数处于区间[mid, largest]的论文的数量
            int minCite = C[mid];   // minCite: 上述区间的论文引用量的最小值
            if (count <= minCite)
                right = mid;
            else
                left = mid + 1; 
        }
        /*
        跳出while循环后，left=right，只剩下1个元素。为什么我们在 return 语句中检查 HIndex?
        情况 1：如果代码执行过程中, right 至少有一次出现 right = mid 的情况，那么循环结束时right 必须是 HIndex。
        情况 2：right 永远不出现right = mid的情况，即程序永远不会跳到 right = mid，那么循环结束时 right 可以是 HIndex，也可以不是。因此我们需要单独进行检查。
        */
        return (C[right] >= n - right) ? n - right : 0;
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