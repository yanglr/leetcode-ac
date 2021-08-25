import java.util.Stack;

public class Leetcode84 {
    public int largestRectangleArea(int[] heights) {
        if (heights == null || heights.length == 0) return 0;

        int[] tempArrs = new int[heights.length + 2];
        System.arraycopy(heights, 0, tempArrs, 1, heights.length);
        Stack<Integer> stack = new Stack<>();
        int area = 0;
        for (int i = 0; i < tempArrs.length; i++) {
            while (!stack.isEmpty() && tempArrs[i] < tempArrs[stack.peek()]) {
                int height = tempArrs[stack.pop()];
                area = Math.max(area, (i - stack.peek() - 1) * height);
            }
            stack.push(i); // push: 数组下标
        }
        return area;
    }
    
    // Test
    public static void main(String[] args) {
        int[] heights = { 2, 1, 5, 6, 2, 3 };
        Leetcode84 sol = new Leetcode84();
        int res = sol.largestRectangleArea(heights);

        System.out.println(res);
    }
}