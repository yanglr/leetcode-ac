#include <string>
#include <sstream>
#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string v1, string v2) {
        if (v1 == v2) return 0;

        const int len1 = v1.size(), len2 = v2.size();
        int i = 0, j = 0;
        while (i < len1 || j < len2)
        {
            int num1 = 0; // 记录字符串v1中相邻两个dot字符间的数字(不包含首尾的点.字符)
            int num2 = 0; // 记录字符串v2中相邻两个dot字符间的数字
            while (i < len1 && v1[i] != '.')
            {
                int newDigit = v1[i++] - '0';
                num1 = num1 * 10 + newDigit;
            }
            while (j < len2 && v2[j] != '.')
            {
                int newDigit = v2[j++] - '0';
                num2 = num2 * 10 + newDigit;
            }
            if (num1 > num2) return 1;
            else if (num1 < num2) return -1;

            i++;
            j++;
        }
        return 0;
    }
};

// Test
int main()
{
    Solution sol;
    string version1 = "7.5.2.4", version2 = "7.5.3";
    auto res = sol.compareVersion(version1, version2);
    cout << res << endl;
    
    return 0;
}