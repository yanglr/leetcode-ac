class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();  // nums的元素都 >= 0
        vector<int> preSum(len + 1, 0);
        for (int i = 1; i <= len; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        for (int i = 0; i < len; i++) {
            for (int j = i+2; j <= len; j++)
            {
                if (k == 0) {
                    if (preSum[j] - preSum[i] == 0)
                        return true;
                }
                else if ((preSum[j] - preSum[i]) % k == 0)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
