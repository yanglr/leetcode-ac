public class Solution {
    public int Divide (int a, int b) {
        if (b == 0) throw new DivideByZeroException();
        if (a == 0) return 0;

        var result = 0;        
        int sign = 1;
        /* 要点
        1、要考虑整数溢出的间题，转换成负数进行计算，因为负数的范围比正数大[int的范围(-2^31 ~ 2^31-1, -2147483648~2147483647)]
        2、用移位实现乘2以及除2的操作
        3、除法的本质是多次减法
        C++不允许负数进行左移操作, C#可以
        */
        if (a > 0) {
            sign = -sign;
            a = -a;
        }
        if (b > 0) {
            sign = -sign;
            b = -b;
        }

        var n = -1;
        while (b >= (int.MinValue >> 1)) {
            b <<= 1;  // b*2^n
            n <<= 1;
        }
        while (true) {
            if (a <= b) {
                result += n;
                a -= b;
            }
            if (n == -1) break;
            b >>= 1;
            n >>= 1;
        }

        if (sign == 1) {
            return result == int.MinValue ? int.MaxValue : -result;
        }
        return result;
    }
}

// Test
void Test () {
    var sol = new Solution ();
    int dividend = 7, divisor = -3;
    Console.WriteLine(sol.Divide(dividend, divisor));
}

Test();