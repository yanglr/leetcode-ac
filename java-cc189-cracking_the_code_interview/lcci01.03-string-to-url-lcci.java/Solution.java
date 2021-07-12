// import java.io.*;

class Solution {
    public String replaceSpaces(String S, int length) {
        if(length > S.length()) return "";
        S = S.substring(0, length);

        StringBuilder res = new StringBuilder();
        for(int i=0; i < length; i++)
        {
            char ch = S.charAt(i);
            if(ch != ' ')
                res.append(ch);
            else {
                res.append("%20");
            }
        }

        return res.toString();
    }

    // Test
    public static void main(String[] args) {
        Solution sol = new Solution();
        String S = "Mr John Smith    ";
        int length = 14;
        String res = sol.replaceSpaces(S, length);

        System.out.println(res);
    }    
}