#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        const int len = customers.size();
        for (int i = 0; i < len; i++) /* 先统计状态=不生气时的满意度之和(基本盘) */
        {
            if (grumpy[i] == 0)
                sum += customers[i];            
        }
        int maxScrore = 0;
        for (int i = 0; i < len; i++) /* 遍历滑动窗口右端点i */
        {
            if (grumpy[i] == 1) /* 新加入滑动窗口的1分钟是暴躁的, 可以用技能压制住 */
                sum += customers[i];     
            if (i - minutes >= 0 && grumpy[i - minutes] == 1) /* 从滑动窗口中拿掉最前面的1分钟时, 如果是暴躁的, 技能就无法压制了, 此时会生效 */
                sum -= customers[i - minutes];
            maxScrore = max(maxScrore, sum);   
        }
        return maxScrore;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> customers = {4, 10, 10};
    vector<int> grumpy = {1, 1, 0};
    int X = 2;
    auto res = sol.maxSatisfied(customers, grumpy, X);
    cout << res << endl;

    return 0;
}