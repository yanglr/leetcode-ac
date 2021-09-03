#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int> &data) {
        int remain = 0; // remain: 还有几个字符(也就是还剩下几段8个bit?)需要检测
        for (int& num : data)
        {
            if (remain == 0) /* 检查开始的8个bit */
            {
                if ((num >> 7) == 0b0) remain = 0;          /* 直接删掉末尾的7位, 看二进制表示下的第1位是不是0 */
                else if ((num >> 5) == 0b110) remain = 1;   /* 删掉末尾的5位, 看二进制表示下是不是以110开头 */
                else if ((num >> 4) == 0b1110) remain = 2;
                else if ((num >> 3) == 0b11110) remain = 3;
                else return false;
            }
            else /* 依次检查第1段8个bit以外的剩下段8个bit */
            {
                if ((num >> 6) != 0b10) return false;
                remain--;
            }
        }
        return remain == 0;
    }
};

// Test
int main()
{
    Solution sol;
    vector<int> data = {197, 130, 1};
    auto res = sol.validUtf8(data);
    cout << (res == true ? "True" : "False") << endl;

    return 0;
}