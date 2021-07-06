class Solution {
    public int singleNumber(int[] nums)
    {
        int[] bits = new int[32];
        for (int num : nums)
        {
            for (int i = 0; i < 32; i++)
            {
                bits[i] = bits[i] + ((num >> i) & 1); // num>>i: [二进制下移位]丢掉num末尾i个bit位,
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

    // Test
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {2,2,3,2};
        int res = sol.singleNumber(nums);
        System.out.println(res);
    }
}