#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32);

        for (auto num : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                bits[i] += (num >> i) & 1; // num>>i: [二进制下移位]丢掉num末尾i个bit位,     
                  // digit & 1 用于高位清零, 检查数字的最后一位是否为偶数, 比number%2速度快
                  // 于是最后的作用是将第i位转换为二进制的 0/1
            }            
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            res += (bits[i] % 3) << i;
        }
        
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = { 0,1,0,1,0,1,99 };
    printf("%d ", sol.singleNumber(nums));
    return 0;
}