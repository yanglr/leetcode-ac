/** 如果有多种方法, 可以将文件名和class 名字都改为 Leetcode1_method2或Leetcode1b 这种格式 */
class Leetcode405b {
    public String toHex(int num) {
        String res = "";
        long N = num;     // 预处理
        if (N == 0) return "0";
        String dict = "0123456789abcdef";
        if (N < 0) N = 4294967296L + N;  /* 4294967296L就是 0x0000000100000000(16^8=2^32), Java中不使用BigInteger无法存储, 只能hard code在这里了 */
        while (N > 0)
        {
            long lastDigit = N % 16;
            N /= 16;
            res = dict.charAt((int)lastDigit) + res;
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