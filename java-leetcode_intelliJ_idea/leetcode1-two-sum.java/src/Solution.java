import java.util.*;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> dict = new HashMap<Integer, Integer>(); /* HashMap只能装integer，不能装int */
        int[] result = new int[2];
        for (int i = 0; i < nums.length; i++)
        {
            dict.put(nums[i], i); // 顺序的map映射: value->index
        }
        for (int i = 0; i < nums.length; i++)
        {
            int query = target - nums[i];
            if (dict.containsKey(query) && dict.get(query) > i) // dict[query] > i是为了防止重复计算
            {
                result[0] = i;
                result[1] = dict.get(query);
                break;
            }
        }
        return result;
    }

    // Test
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {2,7,11,15};
        int target = 9;
        int[] res = sol.twoSum(nums, target);
        System.out.println(res);
    }
}