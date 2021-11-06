#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0;
        int right = n; // 在区间 [0, n]中搜索
        while (left < right)
        {
            int mid = left + (right - left) / 2;  // 防止溢出
            if (isBadVersion(mid) == true)
                right = mid;
            else left = mid + 1;
        }
        return left;        
    }
    // 以下是自己加的, 提交代码时需删掉
    bool isBadVersion(int num)
    {
        return num == 4; // 把测试数据中bad的值放在这
    }
};

// Test
int main()
{
    Solution sol;
    int n = 5, bad = 4;
    auto res = sol.firstBadVersion(n);
    cout << res << endl;

    return 0;
}