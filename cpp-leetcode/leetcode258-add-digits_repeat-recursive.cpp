#include <algorithm>
#include <iostream>
using namespace std;

/* 此题递归法更快, 0 ms */
class Solution {
public:
    int addDigits(int num) {        
        if(num < 10) /* 注意临界条件, 应使用 <10 或 ≤ 9 */
            return num;

        long sum = 0;
        while(num > 0)
        {
            long lastDigit = num % 10;
            sum += lastDigit;
            num /= 10;
        }

        return addDigits(sum);        /* 再调用1次以免还剩下的数位数＞1 */
    }
};

// Test
int main()
{
    Solution sol;
    int n = 222222222;
    auto res = sol.addDigits(n);
    cout << res << endl;

    return 0;
}