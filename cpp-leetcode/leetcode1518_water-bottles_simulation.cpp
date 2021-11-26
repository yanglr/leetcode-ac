#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int numWaterBottles(int bot, int exc) { /* bot: 一开始酒的瓶数, exc: 换一瓶新酒需要的空瓶数 */
        int res = bot; 
        while (bot >= exc)
        {
            res += bot/exc;            // 当前次循环可以新换来的酒的瓶数
            bot = bot/exc + bot % exc; /* 更新总的酒瓶数: 新换来的酒喝完后就成了空瓶, 与当前没用完的酒瓶放在一起, 为下一轮循环做准备 */
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int bot = 24;
    int exc = 4;
    auto res = sol.numWaterBottles(bot, exc);
    cout << res << endl;

    return 0;
}