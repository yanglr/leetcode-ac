#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        s.erase(0, s.find_first_not_of(' '));  //去前导空格
        if(s == "") return 0;
        if((s[0] == '-' && s[1] =='+') || (s[0]=='+' && s[0] == '-')) return 0; //两种符号直接特判
        bool is_neg = false;
        if(s[0] == '-') 
        {
            is_neg = true; 
            s.erase(0,1);
        }
        if(s[0] == '+') s.erase(0,1);
        
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            if( !isdigit(s[i]))
                break;
            int digit = s[i] - '0';
            if(res > (INT_MAX - digit) / 10){  /* 假如循环结束后 res > INT_MAX(/比*更不易越界，所以改用/处理)，这里进行特殊处理 */
                if(is_neg)
                    return INT_MIN;
                return INT_MAX;
            }
            res = res * 10 + digit;  /* 向右扫描, 每移1位，高位x10, sum = sum*10 + digit, 不断迭代 */
        }
        return is_neg ? -res : res;
    }
};

// Test
int main()
{
    Solution sol;
    string str = "-5------+";
    int res = sol.myAtoi(str);
    cout << res << endl;

    return 0;
}