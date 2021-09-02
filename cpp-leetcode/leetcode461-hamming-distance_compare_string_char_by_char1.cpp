#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        string s1 = toBinary(x);
        string s2 = toBinary(y);
        int n1 = s1.size(), n2 = s2.size();
        int maxLen = max(n1, n2);
        if (n1 < n2) s1.insert(s1.begin(), n2 - n1, '0');
        if (n1 > n2) s2.insert(s2.begin(), n1 - n2, '0');
        int distance = 0;
        for (int i = 0; i < maxLen; i++)
        {
            if (s1[i] != s2[i]) distance++;
        }
        return distance;        
    }
    string toBinary(long n)  /* 非负整数转二进制表示的字符串 */
    {
        string res = "";
        while (n > 0)
        {
            char r = n % 2 + '0';
            res.push_back(r);     /* 记住: 放进去的结果会导致低位在前, 高位在后 */
            n /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// Test
int main()
{
    Solution sol;
    int x = 1, y = 4;
    auto res = sol.hammingDistance(x, y);
    cout << res << endl;

    return 0;
}