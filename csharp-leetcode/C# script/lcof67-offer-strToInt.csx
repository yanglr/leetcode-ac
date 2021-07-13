public class Solution {
    public int StrToInt(string str) {
        char[] c = str.Trim().ToCharArray();
        if(c.Length == 0) return 0;
        int res = 0, boundray = int.MaxValue / 10;
        int i = 1, sign = 1;
        if(c[0] == '-') sign = -1;
        else if(c[0] != '+') i = 0;
        for(int j = i; j < c.Length; j++) {
            if(c[j] < '0' || c[j] > '9') break;
            if(res > boundray || res == boundray && c[j] > '7')
                return sign == 1 ? int.MaxValue : int.MinValue;
            res = res * 10 + (c[j] - '0');
        }
        return sign * res;        

    }
}

// Test
void Test () {
    var sol = new Solution ();
    var input = "4193 with words";
    Console.WriteLine (sol.StrToInt(input));
}

Test ();