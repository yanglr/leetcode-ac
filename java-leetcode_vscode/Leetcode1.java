import java.util.Arrays;

class Leetcode1 {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        // 双指针, 先固定一个
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        Leetcode1 sol = new Leetcode1();
        int[] nums = { 2, 1, 5, 6, 2, 3 };
        int target = 7;
        int[] res = sol.twoSum(nums, target);
        
        System.out.println(Arrays.toString(res));
    }
}