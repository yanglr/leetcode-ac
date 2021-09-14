import java.util.*;
public class Leetcode93b {
    public List<String> restoreIpAddresses(String s) {
        List<String> res = new ArrayList<> ();
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                for (int k = 1; k < 4; k++) {
                    for (int m = 1; m < 4; m++) {
                        if (i + j + k + m != s.length()) {
                            continue;
                        }
                        int a = Integer.valueOf(s.substring(0, i));
                        int b = Integer.valueOf(s.substring(i, i + j));
                        int c = Integer.valueOf(s.substring(i + j, i + j + k));

                        int d = Integer.valueOf(s.substring(i + j + k));
                        if (a <= 255 && b <= 255 && c <= 255 && d <= 255) {
                            String temp = a + "." + b + "." + c + "." + d;
                            /* 处理先导0, "0.0.0.0"是合法的, 而"0.01.0.0"不是, 下面的+3是表示3个点. */
                            if (temp.length() == s.length() + 3) {
                                res.add(temp);
                            }
                        }
                    }
                }
            }
        }
        return res;        
    }
    public static void main(String[] args) {
        Leetcode93b sol = new Leetcode93b();
        String s = "25525511135";
        List<String> res = sol.restoreIpAddresses(s);
        
        System.out.println(Arrays.toString(res.toArray()));
    }
}