#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++)  /* nums数组中每个数nums[i] 都是int 32  */
        {  
            int sum = 0;
            for (int num : nums)
            {
                sum += ((num >> i) & 1); /* 取出第i位二进制位的值, 并累加各位数字(0/1), 假如没出现落单的数, 根据题意目前拿到的数都出现了3次, 累加和必然能被3整除. 假如不能整除, 说明那个落单的数已出现, 且落单的那个数的第i位是1不是0. */
            }
            if (sum % 3 == 1)
                res += (1 << i); /* 既然知道了落单的数中哪些二进制为是1, 那么对数位是1的二进制位加权求和即为该数 */
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};
    printf("%d ", sol.singleNumber(nums));
    return 0;
}