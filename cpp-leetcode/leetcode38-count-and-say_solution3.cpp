#include <string>
#include <iostream>
// #include <algorithm>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n <= 0) return "";
        string res = "1";
        while (--n) {
            string curStr = "";
            for (int i = 0; i < res.size(); ++i) {
                int count = 1; // 出现第一个新字符, count置为1
                while (i + 1 < res.size() && res[i] == res[i + 1]) {  /* 这里与上1层循环用的是同一个i, 且区间是上层循环的子区间, 故时间复杂度是O(n^2) */
                    count++;
                    i++;
                }
                curStr += to_string(count) + res[i];
            }
            res = curStr;  // 将结果用作下一轮循环的初始值
        }
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int n = 9;    
    string res = sol.countAndSay(n);
    cout << res << endl;

    return 0;
}