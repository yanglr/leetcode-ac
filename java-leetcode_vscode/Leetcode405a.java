import java.util.*;

/** 如果有多种方法, 可以将文件名和class 名字都改为 Leetcode1_method2或Leetcode1b 这种格式 */
class Leetcode405a {
        public String toHex(int num) {
            String res = "";
            long N = num; // 预处理
            if (N == 0)
                return "0";
            HashMap<Integer, Character> dict = new HashMap<Integer, Character>() {
                {
                    put(0, '0');
                    put(1, '1');
                    put(2, '2');
                    put(3, '3');
                    put(4, '4');
                    put(5, '5');
                    put(6, '6');
                    put(7, '7');
                    put(8, '8');
                    put(9, '9');
                    put(10, 'a');
                    put(11, 'b');
                    put(12, 'c');
                    put(13, 'd');
                    put(14, 'e');
                    put(15, 'f');
                }
            };
            if (N < 0) N = 4294967296L + N; /* 4294967296L就是 0x0000000100000000(16^8=2^32), Java中
                                             * 不使用BigInteger无法存储该数, 只能hard code在这里了
                                             */
            while (N > 0) {
                long lastDigit = N % 16;
                N /= 16;
                res = dict.get((int) lastDigit) + res;
            }
            return res;
        }
        
    public static void main(String[] args) {
        Leetcode405a sol = new Leetcode405a();
        int num = 7;
        String res = sol.toHex(num);        
        System.out.println(res);
    }
}