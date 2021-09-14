#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> nums;
        for (int i = left; i <= right; i++)
        {
            if (isSelfDiv(i)) nums.push_back(i);
        }
        return nums;
    }
    bool isSelfDiv(int n)
    {
        if (n < 10) return true;
        if (n % 10 == 0) return false;

        int temp = n;
        while (temp != 0)        
        {
            int rem = temp % 10;
            if (rem == 0) return false;
            if (rem > 1 && n % rem != 0)  // 原数不是末位数字倍数的数需要排除
                return false;
            temp /= 10;
        }
        return true;
    }
};

// Test
int main()
{
    Solution sol;
    int left = 2, right = 50;
    vector<int> res = sol.selfDividingNumbers(left, right);
    for (int i : res)
        printf("%d ", i);
    return 0;
}