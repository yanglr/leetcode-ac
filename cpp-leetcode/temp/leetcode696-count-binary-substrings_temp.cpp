#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        // 先考察子串"01"、子串"10"是否存在, 然后向外扩展 ... 直到循环变量达到 len/2
        vector<string> vect1 = {"01"}; // 存"01"及其扩展
        vector<string> vect2 = {"10"}; // 存"10"及其扩展
        int len = s.size();
        extend(vect1, 0, len);
        extend(vect2, 1, len);

        int count = 0;
        for (auto str : vect1)
        {
            int startPos = 0;
            while (string::npos != (startPos = s.find(str, startPos)))
            {
                ++startPos;
                count++;
            }
        }
        for (auto str : vect2)
        {
            int startPos = 0;
            while (string::npos != (startPos = s.find(str, startPos)))
            {
                ++startPos;
                count++;
            }
        }
        return count;
    }
    void extend(vector<string>& vect, int startDigit, int len)
    {
        if (startDigit == 0)
        {
            for (int i = 1; i < len/2; i++)
            {
                vect.push_back("0" + vect[i - 1] + "1");
            }
        }
        if (startDigit == 1)
        {
            for (int i = 1; i < len/2; i++)
            {
                vect.push_back("1" + vect[i - 1] + "0");
            }
        }
    }
};

// Test
int main()
{
    Solution sol;
    string str = "00110011";
    auto res = sol.countBinarySubstrings(str);
    
    cout << res << endl; 

    return 0;
}