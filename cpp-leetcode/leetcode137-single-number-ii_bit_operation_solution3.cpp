#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        int bits1 = 0, bits2 = 0;
        for (int num : nums)
        {
            int bits1_new = 0, bits2_new = 0;
            for (int i = 0; i < 32; i++)
            {
                int hi = (bits1 >> i) & 1;
                int low = (bits2 >> i) & 1;
                int sum = (hi * 2 + low + ((num >> i) & 1)) % 3;
                bits1_new += (sum / 2) << i;
                bits2_new += (sum % 2) << i;
            }
            bits1 = bits1_new, bits2 = bits2_new;
        }
        
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            res += ((bits2 >> i) & 1) << i;
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