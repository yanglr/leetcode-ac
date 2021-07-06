/** 重要提示:
 * File name should be renamed to "Solution.java" when run locally.
 * Class name should be changed to "Main" (including test logic in bottom main()) when run in <https://www.onlinegdb.com>.
 */
public class Solution
{
	public final String minWindow(String s, String t)
	{
		if (s == null || t == null || s.length() < t.length())
		{
			return "";
		}

		int[] gapMap = new int[128];
		for (char ch : t.toCharArray()) // 先遍历字符串t来初始化gapMap
		{
			gapMap[ch]++;
		}

		int right = 0;
		int left = 0;
		int gapSum = t.length();
		int start = 0;
		int minLen = Integer.MAX_VALUE;
		while (right < s.length())
		{
			char rch = s.charAt(right);
			if (gapMap[rch] > 0)
				gapSum--;
			gapMap[rch]--; /* 如果该字符不是需要的，加到map中，每出现一次累记1个-1。如果该字符在map中有的话就减1表示抵消一个。*/

			if (gapSum == 0)
			{
				while (left < right && gapMap[s.charAt(left)] < 0) // 右移左边界, 依次扔掉当前的字符, gapMap中相应的值+1
				{
					gapMap[s.charAt(left++)]++;
				}
				if (right - left + 1 < minLen) // 更新窗口长度
				{
					minLen = right - left + 1;
					start = left;
				}

				// 当while循环结束, 即字符在gapMap中的值当为0且左边界继续右移时
				gapMap[s.charAt(left++)]++;
				gapSum++;
			}

			right++;
		}
		return minLen == Integer.MAX_VALUE ? "" : s.substring(start, start + minLen);
	}
	
	// Test
	public static void main(String[] args) {
        Solution sol = new Solution();
        String s = "ADOBECODEBANC", t = "ABC";
        String res = sol.minWindow(s, t);
        System.out.println(res);
    }
}