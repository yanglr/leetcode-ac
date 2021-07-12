public class Solution {
    int findMajorityElement(int[] nums) {
        int candidate = getCandidate(nums);
        return validate(nums, candidate) ? candidate : -1;
    }
    int getCandidate(int[] nums) {
        int majority = 0;
        int count = 0;
        for (int n : nums) {
            if (count == 0) { // 前面的集合中没有主要元素
                majority = n;
            }
            if (n == majority) {
                count++;
            } else {
                count--;
            }
        }
        return majority;
    }

    boolean validate(int[] nums, int majority) {
        int count = 0;
        for (int n : nums) {
            if (n == majority) {
                count++;
            }
        }

        return count > nums.length / 2;
    }
}
