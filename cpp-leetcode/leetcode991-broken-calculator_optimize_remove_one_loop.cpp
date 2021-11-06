#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if (startValue > target) return startValue - target;

        int count = 0;
        while (startValue < target)
        {
            if (target % 2 == 0)
            {
                target /= 2;
                count++;
            }
            else {
                target += 1;
                count++;
            }
        }         
        return count + (startValue - target); /* 一旦出现 startValue >= target 的情形, 方法1代码中的第二个while循环就不需要了 */
    }
};
        
// Test
int main()
{
    Solution sol;
    int startValue = 3;
    int target = 10;
    auto res = sol.brokenCalc(startValue, target);
    cout << res << endl;

    return 0;
}