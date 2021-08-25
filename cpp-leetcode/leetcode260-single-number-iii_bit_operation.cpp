#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {        
        int theXor = 0;
        for (int num : nums)   // 对nums数组中的所有数异或运算, 算出两个落单数的异或结果
            theXor ^= num;
        int mask = 1;
        while ((theXor & mask) == 0) /*  从低位开始向高位扫描, 找出两数的异或结果中的第1个1, 这恰好是两个落单数第一个不同的bit位  */
            mask <<= 1;
        /* 接下来, 想办法把所有数分为2组, 且每个组只有1个落单的数, 只需要找一个概率均为50%的条件即可, 比如判断数组中的每一个元素与mask最高位的同一个位置的二进制位是1还是0 */
        int group1 = 0, group2 = 0;
        vector<int> res;
        for (int num : nums)   
        {
            if (num & mask)
                group1 ^= num; 
            else group2 ^= num;
        }
        res = {group1, group2};
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    printf("%d ", sol.singleNumber(nums));

    return 0;
}